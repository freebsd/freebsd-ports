/*******************************************************************************
 * Copyright (c) 2017, 2024 IBM Corporation and others.
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     Julien HENRY - Linux implementation
 *     Red Hat Inc. - add validation method to handle KDE failures
 *     Red Hat Inc. - modified to make JNA version
 *******************************************************************************/
package org.eclipse.equinox.internal.security.linux;

import java.nio.charset.StandardCharsets;
import java.security.SecureRandom;
import java.util.Map;

import javax.crypto.spec.PBEKeySpec;

import org.eclipse.equinox.internal.security.auth.AuthPlugin;
import org.eclipse.equinox.internal.security.storage.Base64;
import org.eclipse.equinox.internal.security.storage.provider.IValidatingPasswordProvider;
import org.eclipse.equinox.security.storage.provider.IPreferencesContainer;
import org.eclipse.equinox.security.storage.provider.PasswordProvider;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.PointerByReference;

public class LinuxPasswordProvider extends PasswordProvider implements IValidatingPasswordProvider {

	/**
	 * The length of the randomly generated password in bytes
	 */
	private static final int PASSWORD_LENGTH = 64;

	private static final String SECRET_COLLECTION_DEFAULT = "default"; //$NON-NLS-1$
	// open flags = (RTLD_NODELETE | RTLD_GLOBAL | RTLD_LAZY)
	private static final Map<String, Object> LIB_LOAD_OPTIONS = Map.of(Library.OPTION_OPEN_FLAGS, 0x1101);

	private final SecretSchema fEquinoxSchema = new SecretSchema("org.eclipse.equinox", //$NON-NLS-1$
			SecretSchemaFlags.SECRET_SCHEMA_NONE, new SecretSchemaAttribute(null, 0));
	private LibSecret fLibSecret;
	private LibGio fLibGio;

	private interface LibGio extends Library {
		Pointer g_bus_get_sync(int bus_type, Pointer cancellable, PointerByReference gerror);

		void g_error_free(Pointer error);

		GList g_list_append(GList list, Pointer data);
	}

	private interface LibSecret extends Library {
		Pointer secret_service_get_sync(int flags, Pointer cancellable, PointerByReference gerror);

		Pointer secret_collection_for_alias_sync(Pointer service, final String alias, int flags, Pointer cancellable,
				PointerByReference gerror);

		boolean secret_collection_get_locked(Pointer self);

		String secret_collection_get_label(Pointer self);

		int secret_service_unlock_sync(Pointer service, GList objects, Pointer cancellable, PointerByReference unlocked,
				PointerByReference error);

		String secret_password_lookup_sync(SecretSchema schema, Pointer cancellable, PointerByReference error,
				Object... attributes);

		boolean secret_password_store_sync(SecretSchema schema, String collection, String label, String password,
				Pointer cancellable, PointerByReference error, Object... attributes);
	}

	private void unlockSecretService() {

		fLibGio = Native.load("gio-2.0", LibGio.class, LIB_LOAD_OPTIONS); //$NON-NLS-1$

		PointerByReference gerror = new PointerByReference();
		gerror.setValue(Pointer.NULL);
		fLibGio.g_bus_get_sync(GBusType.G_BUS_TYPE_SESSION, Pointer.NULL, gerror);
		requireNoError(gerror, "Unable to get DBus session bus: "); //$NON-NLS-1$

		fLibSecret = Native.load("secret-1", LibSecret.class, LIB_LOAD_OPTIONS); //$NON-NLS-1$
		Pointer secretService = fLibSecret.secret_service_get_sync(SecretServiceFlags.SECRET_SERVICE_LOAD_COLLECTIONS,
				Pointer.NULL, gerror);
		requireNoError(gerror, "Unable to get secret service: "); //$NON-NLS-1$

		Pointer defaultCollection = fLibSecret.secret_collection_for_alias_sync(secretService,
				SECRET_COLLECTION_DEFAULT, SecretCollectionFlags.SECRET_COLLECTION_NONE, Pointer.NULL, gerror);
		requireNoError(gerror, "Unable to get secret collection: "); //$NON-NLS-1$
		if (defaultCollection == Pointer.NULL) {
			throw new SecurityException("Unable to find default secret collection"); //$NON-NLS-1$
		}
		if (fLibSecret.secret_collection_get_locked(defaultCollection)) {
			fLibSecret.secret_collection_get_label(defaultCollection);
			GList list = fLibGio.g_list_append(null, defaultCollection);
			PointerByReference unlocked = new PointerByReference();
			fLibSecret.secret_service_unlock_sync(secretService, list, Pointer.NULL, unlocked, gerror);
			fLibGio.g_error_free(unlocked.getValue());
			fLibGio.g_error_free(list.getPointer());

			requireNoError(gerror, "Unable to unlock: "); //$NON-NLS-1$
		}

	}

	private String getMasterPassword() throws SecurityException {
		unlockSecretService();
		PointerByReference gerror = new PointerByReference();
		String password = fLibSecret.secret_password_lookup_sync(fEquinoxSchema, Pointer.NULL, gerror, Pointer.NULL);

		requireNoError(gerror, ""); //$NON-NLS-1$
		if (password == null) {
			throw new SecurityException("Unable to find password"); //$NON-NLS-1$
		}
		return new String(password.getBytes(), StandardCharsets.UTF_8);
	}

	private void saveMasterPassword(String password) throws SecurityException {
		unlockSecretService();
		PointerByReference gerror = new PointerByReference();

		String passwordUTF8 = new String(password.getBytes(), StandardCharsets.UTF_8);

		fLibSecret.secret_password_store_sync(fEquinoxSchema, SECRET_COLLECTION_DEFAULT, "Equinox master password", //$NON-NLS-1$
				passwordUTF8, Pointer.NULL, gerror, Pointer.NULL);

		requireNoError(gerror, ""); //$NON-NLS-1$
	}

	private void requireNoError(PointerByReference gerror, String details) {
		if (gerror.getValue() != Pointer.NULL) {
			GError error = new GError(gerror.getValue());
			String message = error.message;
			fLibGio.g_error_free(gerror.getValue());
			throw new SecurityException(details + message);
		}
	}

	@Override
	public PBEKeySpec getPassword(IPreferencesContainer container, int passwordType) {

		boolean newPassword = (passwordType & CREATE_NEW_PASSWORD) != 0;
		boolean passwordChange = (passwordType & PASSWORD_CHANGE) != 0;

		if (!newPassword && !passwordChange) {
			try {
				return new PBEKeySpec(getMasterPassword().toCharArray());
			} catch (SecurityException e) {
				AuthPlugin.getDefault().logError(LinuxPasswordProviderMessages.getMasterPasswordError, e);
				return null;
			}
		}

		byte[] rawPassword = new byte[PASSWORD_LENGTH];
		new SecureRandom().nextBytes(rawPassword);
		String newPasswordString = Base64.encode(rawPassword);

		// add info message in the log
		AuthPlugin.getDefault().logMessage(LinuxPasswordProviderMessages.newMasterPasswordGenerated);

		try {
			saveMasterPassword(newPasswordString);
			return new PBEKeySpec(newPasswordString.toCharArray());
		} catch (SecurityException e) {
			AuthPlugin.getDefault().logError(LinuxPasswordProviderMessages.saveMasterPasswordError, e);
			return null;
		}
	}

	@Override
	public boolean isValid() {
		try {
			unlockSecretService();
			return true;
		} catch (SecurityException e) {
			return false;
		}
	}

}
