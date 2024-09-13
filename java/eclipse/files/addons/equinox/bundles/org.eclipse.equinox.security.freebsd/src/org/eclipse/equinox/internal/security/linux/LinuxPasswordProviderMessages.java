/*******************************************************************************
 * Copyright (c) 2017 IBM Corporation and others.
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
 *******************************************************************************/
package org.eclipse.equinox.internal.security.linux;

import org.eclipse.osgi.util.NLS;

public class LinuxPasswordProviderMessages extends NLS {

	private static final String BUNDLE_NAME = "org.eclipse.equinox.internal.security.linux.messages"; //$NON-NLS-1$

	public static String getMasterPasswordError;
	public static String saveMasterPasswordError;
	public static String newMasterPasswordGenerated;

	static {
		// load message values from bundle file
		reloadMessages();
	}

	public static void reloadMessages() {
		NLS.initializeMessages(BUNDLE_NAME, LinuxPasswordProviderMessages.class);
	}
}
