/*******************************************************************************
 * Copyright (c) 2021 Red Hat Inc. and others
 *
 * This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License 2.0
 * which accompanies this distribution, and is available at
 * https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *     Red Hat Inc. - initial API and implementation
 *******************************************************************************/
package org.eclipse.core.net;

import java.io.IOException;
import java.net.URI;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Objects;
import java.util.Properties;

import org.eclipse.core.internal.net.AbstractProxyProvider;
import org.eclipse.core.internal.net.Activator;
import org.eclipse.core.internal.net.Policy;
import org.eclipse.core.internal.net.ProxyData;
import org.eclipse.core.internal.net.StringUtil;
import org.eclipse.core.net.proxy.IProxyData;

import com.sun.jna.Library;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.PointerByReference;

/**
 * JNA version of org.eclipse.core.internal.net.UnixProxyProvider
 *
 * @author jjohnstn
 *
 */
public class ProxyProvider extends AbstractProxyProvider {

	private static LibGio fLibGio;

	private static Pointer proxySettings = Pointer.NULL;
	private static Pointer httpProxySettings = Pointer.NULL;
	private static Pointer httpsProxySettings = Pointer.NULL;
	private static Pointer socksProxySettings = Pointer.NULL;
	private static Pointer ftpProxySettings = Pointer.NULL;

	private static final String ENABLE_GNOME = Activator.ID + ".enableGnome"; //$NON-NLS-1$

	private static final String LIBRARY_NAME = "gio-2.0"; //$NON-NLS-1$

	private static boolean isGnomeLibLoaded = false;

	static {
		// Load the GSettings JNI library if org.eclipse.core.net.enableGnome is specified
		String value = System.getProperty(ENABLE_GNOME);
		if ("".equals(value) || "true".equals(value)) { //$NON-NLS-1$ //$NON-NLS-2$
			initializeSettings();
		}
	}

	public ProxyProvider() {
		// no initialization required
	}

	@Override
	public IProxyData[] select(URI uri) {
		String[] nonProxyHosts = getNonProxiedHosts();
		if (nonProxyHosts != null) {
			String host = uri.getHost();
			for (String nonProxyHost : nonProxyHosts) {
				if (StringUtil.hostMatchesFilter(host, nonProxyHost)) {
					return new IProxyData[0];
				}
			}
		}
		IProxyData[] proxies = new IProxyData[0];
		if (uri.getScheme() != null) {
			ProxyData pd = getSystemProxyInfo(uri.getScheme());
			proxies = pd != null ? new IProxyData[] { pd } : new IProxyData[0];
		} else {
			proxies = getProxyData();
		}
		if (Policy.DEBUG) {
			Policy.debug("LinuxProxyProvider#select result for [" + uri + "]"); //$NON-NLS-1$ //$NON-NLS-2$
			for (IProxyData proxy : proxies) {
				System.out.println("	" + proxy); //$NON-NLS-1$
			}
		}
		return proxies;
	}

	@Override
	public IProxyData[] getProxyData() {
		String[] commonTypes = new String[] { IProxyData.HTTP_PROXY_TYPE,
				IProxyData.SOCKS_PROXY_TYPE, IProxyData.HTTPS_PROXY_TYPE };
		return getProxyForTypes(commonTypes);
	}

	private IProxyData[] getProxyForTypes(String[] types) {
		ArrayList<IProxyData> allData = new ArrayList<>();
		for (String type : types) {
			ProxyData pd = getSystemProxyInfo(type);
			if (pd != null && pd.getHost() != null) {
				allData.add(pd);
			}
		}
		return allData.toArray(new IProxyData[0]);
	}

	@Override
	public String[] getNonProxiedHosts() {
		String[] npHosts;

		if (Policy.DEBUG_SYSTEM_PROVIDERS)
			Policy.debug("Getting no_proxy"); //$NON-NLS-1$

		// First try the environment variable which is a URL
		String npEnv = getEnv("no_proxy"); //$NON-NLS-1$
		if (npEnv != null) {
			npHosts = StringUtil.split(npEnv, new String[] { "," }); //$NON-NLS-1$
			for (int i = 0; i < npHosts.length; i++)
				npHosts[i] = npHosts[i].trim();
			if (Policy.DEBUG_SYSTEM_PROVIDERS) {
				Policy.debug("Got Env no_proxy: " + npEnv); //$NON-NLS-1$
				debugPrint(npHosts);
			}
			return npHosts;
		}

		if (isGnomeLibLoaded) {
			try {
				npHosts = getGSettingsNonProxyHosts();
				if (npHosts != null && npHosts.length > 0) {
					if (Policy.DEBUG_SYSTEM_PROVIDERS) {
						Policy.debug("Got Gnome no_proxy"); //$NON-NLS-1$
						debugPrint(npHosts);
					}
					return npHosts;
				}
			} catch (UnsatisfiedLinkError e) {
				// The library should be loaded, so this is a real exception
				Activator.logError(
						"Problem during accessing Gnome library", e); //$NON-NLS-1$
			}
		}

		return new String[0];
	}

	// Returns null if something wrong or there is no proxy for the protocol
	protected ProxyData getSystemProxyInfo(String protocol) {
		ProxyData pd = null;
		String envName = null;

		if (Policy.DEBUG_SYSTEM_PROVIDERS)
			Policy.debug("Getting proxies for: " + protocol); //$NON-NLS-1$

		try {
			// protocol schemes are ISO 8859 (ASCII)
			protocol = protocol.toLowerCase(Locale.ENGLISH);

			// First try the environment variable which is a URL
			envName = protocol + "_proxy"; //$NON-NLS-1$
			String proxyEnv = getEnv(envName);
			if (Policy.DEBUG_SYSTEM_PROVIDERS)
				Policy.debug("Got proxyEnv: " + proxyEnv); //$NON-NLS-1$

			if (proxyEnv != null) {
				int colonInd = proxyEnv.indexOf(":"); //$NON-NLS-1$
				if (colonInd !=-1 && proxyEnv.length() > colonInd + 2 && !"//".equals(proxyEnv.substring(colonInd + 1, colonInd + 3))) { //$NON-NLS-1$
					proxyEnv = "http://" + proxyEnv; //$NON-NLS-1$
				}
				URI uri = new URI(proxyEnv);
				pd = new ProxyData(protocol);
				pd.setHost(Objects.requireNonNull(uri.getHost(), "no host in " + proxyEnv)); //$NON-NLS-1$
				int port = uri.getPort();
				if (port == -1) {
					throw new IllegalStateException("no port in " + proxyEnv); //$NON-NLS-1$
				}
				pd.setPort(port);
				String userInfo = uri.getUserInfo();
				if (userInfo != null) {
					String user = null;
					String password = null;
					int pwInd = userInfo.indexOf(':');
					if (pwInd >= 0) {
						user = userInfo.substring(0, pwInd);
						password = userInfo.substring(pwInd + 1);
					} else {
						user = userInfo;
					}
					pd.setUserid(user);
					pd.setPassword(password);
				}
				pd.setSource("LINUX_ENV"); //$NON-NLS-1$
				if (Policy.DEBUG_SYSTEM_PROVIDERS)
					Policy.debug("Got Env proxy: " + pd); //$NON-NLS-1$
				return pd;
			}
		} catch (Exception e) {
			Activator.logError(
					"Problem during accessing system variable: " + envName, e); //$NON-NLS-1$
		}

		if (isGnomeLibLoaded) {
			try {
				// Then ask Gnome
				pd = getGSettingsProxyInfo(protocol);
				if (pd != null) {
					if (Policy.DEBUG_SYSTEM_PROVIDERS)
						Policy.debug("Got Gnome proxy: " + pd); //$NON-NLS-1$
					pd.setSource("LINUX_GNOME"); //$NON-NLS-1$
					return pd;
				}
			} catch (UnsatisfiedLinkError e) {
				// The library should be loaded, so this is a real exception
				Activator.logError(
						"Problem during accessing Gnome library", e); //$NON-NLS-1$
			}
		}

		return null;
	}

	private static String getEnv(String env) {
		try {
			return System.getenv(env);
		} catch (Throwable t) {
			// Fall-back to running 'env' directly. Warning this is very slow...
			// up to 200ms
			String cmd[] = { "/bin/sh", //$NON-NLS-1$
					"-c", //$NON-NLS-1$
					"env | grep -i proxy" }; //$NON-NLS-1$
			Properties props = new Properties();
			Process proc = null;
			try {
				proc = Runtime.getRuntime().exec(cmd);
				props.load(proc.getInputStream());
			} catch (IOException e) {
				Activator.logError(
						"Problem during accessing system variable: " + env, e); //$NON-NLS-1$
			} catch (IllegalArgumentException e) {
				Activator.logError(
						"Problem during accessing system variable: " + env, e); //$NON-NLS-1$
			} finally {
				if (proc != null) {
					proc.destroy();
				}
			}
			return props.getProperty(env);
		}
	}

	private void debugPrint(String[] strs) {
		for (int i = 0; i < strs.length; i++)
			System.out.println(i + ": " + strs[i]); //$NON-NLS-1$
	}

	private interface LibGio extends Library {
		Pointer g_settings_new(String schema);
		boolean g_settings_get_boolean(Pointer settings, String key);
		Pointer g_settings_get_string(Pointer settings, String key);
		int g_settings_get_int(Pointer settings, String key);
		PointerByReference g_settings_get_strv(Pointer Settings, String key);
		void g_strfreev(PointerByReference p);
		void g_free(Pointer p);
	}

	private static void initializeSettings() {
		try {
			fLibGio = Native.load(LIBRARY_NAME, LibGio.class);
			proxySettings = fLibGio.g_settings_new ("org.gnome.system.proxy"); //$NON-NLS-1$
			httpProxySettings = fLibGio.g_settings_new ("org.gnome.system.proxy.http"); //$NON-NLS-1$
			httpsProxySettings = fLibGio.g_settings_new ("org.gnome.system.proxy.https"); //$NON-NLS-1$
			socksProxySettings = fLibGio.g_settings_new ("org.gnome.system.proxy.socks"); //$NON-NLS-1$
			ftpProxySettings = fLibGio.g_settings_new ("org.gnome.system.proxy.ftp"); //$NON-NLS-1$
			isGnomeLibLoaded= true;
			if (Policy.DEBUG_SYSTEM_PROVIDERS)
				Policy.debug("Loaded " + //$NON-NLS-1$
						System.mapLibraryName(LIBRARY_NAME) + " library"); //$NON-NLS-1$
		} catch (UnsatisfiedLinkError e) {
			isGnomeLibLoaded= false;
			if (Policy.DEBUG_SYSTEM_PROVIDERS)
				Policy.debug("Could not load library: " //$NON-NLS-1$
						+ System.mapLibraryName(LIBRARY_NAME));
		}
	}

	protected static ProxyData getGSettingsProxyInfo(String protocol) {

		if (protocol == null) {
			return null;
		}

		if (proxySettings == Pointer.NULL) {
			initializeSettings();
		}

		// Everything else applies only if the system proxy mode is manual
		// Auto-configuration is not supported
		Pointer mode = fLibGio.g_settings_get_string(proxySettings, "mode"); //$NON-NLS-1$
		if (!mode.getString(0).equalsIgnoreCase("manual")) { //$NON-NLS-1$
			fLibGio.g_free(mode);
			return null;
		}
		fLibGio.g_free(mode);

		Pointer host;
		int port;

		switch (protocol.toLowerCase()) {
		case "http": //$NON-NLS-1$
			host = fLibGio.g_settings_get_string(httpProxySettings, "host"); //$NON-NLS-1$
			port = fLibGio.g_settings_get_int(httpProxySettings, "port"); //$NON-NLS-1$
			break;
		case "https": //$NON-NLS-1$
			host = fLibGio.g_settings_get_string(httpsProxySettings, "host"); //$NON-NLS-1$
			port = fLibGio.g_settings_get_int(httpsProxySettings, "port"); //$NON-NLS-1$
			break;
		case "ftp": //$NON-NLS-1$
			host = fLibGio.g_settings_get_string(ftpProxySettings, "host"); //$NON-NLS-1$
			port = fLibGio.g_settings_get_int(ftpProxySettings, "port"); //$NON-NLS-1$
			break;
		case "socks": //$NON-NLS-1$
			host = fLibGio.g_settings_get_string(socksProxySettings, "host"); //$NON-NLS-1$
			port = fLibGio.g_settings_get_int(socksProxySettings, "port"); //$NON-NLS-1$
			break;
		default:
			// Unknown/invalid proxy type
			return null;
		}

		ProxyData proxyData = new ProxyData(protocol);
		proxyData.setHost(host.getString(0));
		fLibGio.g_free(host);
		proxyData.setPort(port);

		// Each proxy type is enabled only if the "host" key is non-empty and its "port" key is non-0
		if (proxyData.getHost() == null || proxyData.getPort() == 0) {
			return null;
		}

		if (protocol.equalsIgnoreCase("http")) { //$NON-NLS-1$
			// Authentication applies only to http proxies
			boolean reqAuth = fLibGio.g_settings_get_boolean(httpProxySettings, "use-authentication"); //$NON-NLS-1$
			if (reqAuth) {
				Pointer user = fLibGio.g_settings_get_string(httpProxySettings,	"authentication-user"); //$NON-NLS-1$
				proxyData.setUserid(user.getString(0));
				fLibGio.g_free(user);

				Pointer password = fLibGio.g_settings_get_string(httpProxySettings,	"authentication-password"); //$NON-NLS-1$
				proxyData.setPassword(password.getString(0));
				fLibGio.g_free(password);
			}
		}

		return proxyData;
	}

	protected static String[] getGSettingsNonProxyHosts() {
		if (proxySettings == Pointer.NULL) {
			initializeSettings();
		}

		// Everything else applies only if the system proxy mode is manual
		// Auto-configuration is not supported
		Pointer mode = fLibGio.g_settings_get_string(proxySettings, "mode"); //$NON-NLS-1$
		if (!mode.getString(0).equalsIgnoreCase("manual")) { //$NON-NLS-1$
			fLibGio.g_free(mode);
			return null;
		}
		fLibGio.g_free(mode);

		PointerByReference npHostsArray = fLibGio.g_settings_get_strv(proxySettings, "ignore-hosts"); //$NON-NLS-1$
		String[] npHosts = npHostsArray.getPointer().getStringArray(0);

		fLibGio.g_strfreev(npHostsArray);

		return npHosts;
	}

}

