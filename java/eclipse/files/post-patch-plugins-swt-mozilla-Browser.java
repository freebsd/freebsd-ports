--- plugins/org.eclipse.swt/Eclipse SWT Mozilla/gtk/org/eclipse/swt/browser/Browser.java.orig	Wed Nov 29 14:32:45 2006
+++ plugins/org.eclipse.swt/Eclipse SWT Mozilla/gtk/org/eclipse/swt/browser/Browser.java	Wed Nov 29 14:42:01 2006
@@ -10,15 +10,75 @@
  *******************************************************************************/
 package org.eclipse.swt.browser;
 
-import java.io.*;
-import java.util.*;
-import org.eclipse.swt.*;
-import org.eclipse.swt.widgets.*;
-import org.eclipse.swt.graphics.*;
-import org.eclipse.swt.internal.*;
-import org.eclipse.swt.internal.gtk.*;
-import org.eclipse.swt.internal.mozilla.*;
-import org.eclipse.swt.layout.*;
+import java.io.File;
+import java.io.UnsupportedEncodingException;
+import java.util.Locale;
+import java.util.StringTokenizer;
+
+import org.eclipse.swt.SWT;
+import org.eclipse.swt.SWTError;
+import org.eclipse.swt.SWTException;
+import org.eclipse.swt.graphics.Point;
+import org.eclipse.swt.graphics.Rectangle;
+import org.eclipse.swt.internal.Callback;
+import org.eclipse.swt.internal.Converter;
+import org.eclipse.swt.internal.Library;
+import org.eclipse.swt.internal.gtk.GdkEvent;
+import org.eclipse.swt.internal.gtk.LONG;
+import org.eclipse.swt.internal.gtk.OS;
+import org.eclipse.swt.internal.mozilla.XPCOM;
+import org.eclipse.swt.internal.mozilla.XPCOMObject;
+import org.eclipse.swt.internal.mozilla.nsEmbedString;
+import org.eclipse.swt.internal.mozilla.nsIAppShell;
+import org.eclipse.swt.internal.mozilla.nsIBaseWindow;
+import org.eclipse.swt.internal.mozilla.nsICategoryManager;
+import org.eclipse.swt.internal.mozilla.nsIComponentManager;
+import org.eclipse.swt.internal.mozilla.nsIComponentRegistrar;
+import org.eclipse.swt.internal.mozilla.nsIContextMenuListener;
+import org.eclipse.swt.internal.mozilla.nsICookie;
+import org.eclipse.swt.internal.mozilla.nsICookieManager;
+import org.eclipse.swt.internal.mozilla.nsID;
+import org.eclipse.swt.internal.mozilla.nsIDOMEvent;
+import org.eclipse.swt.internal.mozilla.nsIDOMMouseEvent;
+import org.eclipse.swt.internal.mozilla.nsIDOMWindow;
+import org.eclipse.swt.internal.mozilla.nsIDirectoryService;
+import org.eclipse.swt.internal.mozilla.nsIDocShell;
+import org.eclipse.swt.internal.mozilla.nsIEmbeddingSiteWindow;
+import org.eclipse.swt.internal.mozilla.nsIFile;
+import org.eclipse.swt.internal.mozilla.nsIIOService;
+import org.eclipse.swt.internal.mozilla.nsIInterfaceRequestor;
+import org.eclipse.swt.internal.mozilla.nsILocalFile;
+import org.eclipse.swt.internal.mozilla.nsIPrefBranch;
+import org.eclipse.swt.internal.mozilla.nsIPrefLocalizedString;
+import org.eclipse.swt.internal.mozilla.nsIPrefService;
+import org.eclipse.swt.internal.mozilla.nsIProperties;
+import org.eclipse.swt.internal.mozilla.nsIRequest;
+import org.eclipse.swt.internal.mozilla.nsIServiceManager;
+import org.eclipse.swt.internal.mozilla.nsISimpleEnumerator;
+import org.eclipse.swt.internal.mozilla.nsISupports;
+import org.eclipse.swt.internal.mozilla.nsISupportsWeakReference;
+import org.eclipse.swt.internal.mozilla.nsITooltipListener;
+import org.eclipse.swt.internal.mozilla.nsIURI;
+import org.eclipse.swt.internal.mozilla.nsIURIContentListener;
+import org.eclipse.swt.internal.mozilla.nsIWeakReference;
+import org.eclipse.swt.internal.mozilla.nsIWebBrowser;
+import org.eclipse.swt.internal.mozilla.nsIWebBrowserChrome;
+import org.eclipse.swt.internal.mozilla.nsIWebBrowserChromeFocus;
+import org.eclipse.swt.internal.mozilla.nsIWebBrowserFocus;
+import org.eclipse.swt.internal.mozilla.nsIWebBrowserStream;
+import org.eclipse.swt.internal.mozilla.nsIWebNavigation;
+import org.eclipse.swt.internal.mozilla.nsIWebProgress;
+import org.eclipse.swt.internal.mozilla.nsIWebProgressListener;
+import org.eclipse.swt.internal.mozilla.nsIWindowWatcher;
+import org.eclipse.swt.layout.FillLayout;
+import org.eclipse.swt.widgets.Composite;
+import org.eclipse.swt.widgets.Display;
+import org.eclipse.swt.widgets.Event;
+import org.eclipse.swt.widgets.Label;
+import org.eclipse.swt.widgets.Listener;
+import org.eclipse.swt.widgets.Menu;
+import org.eclipse.swt.widgets.Shell;
+import org.eclipse.swt.widgets.Widget;
 
 /**
  * Instances of this class implement the browser user interface
@@ -175,40 +235,9 @@
 		 * - mozilla17profile/mozilla17profile-gcc should succeed for mozilla 1.7.x and firefox
 		 * - mozilla18profile/mozilla18profile-gcc should succeed for mozilla 1.8.x (seamonkey)
 		 */
-		try {
-			Library.loadLibrary ("swt-mozilla14-profile"); //$NON-NLS-1$
-			usingProfile = true;
-		} catch (UnsatisfiedLinkError e1) {
-			try {
-				Library.loadLibrary ("swt-mozilla17-profile"); //$NON-NLS-1$
-				usingProfile = true;
-			} catch (UnsatisfiedLinkError e2) {
-				try {
-					Library.loadLibrary ("swt-mozilla14-profile-gcc3"); //$NON-NLS-1$
-					usingProfile = true;
-				} catch (UnsatisfiedLinkError e3) {
-					try {
-						Library.loadLibrary ("swt-mozilla17-profile-gcc3"); //$NON-NLS-1$
-						usingProfile = true;
-					} catch (UnsatisfiedLinkError e4) {
-						try {
-							Library.loadLibrary ("swt-mozilla18-profile"); //$NON-NLS-1$
-							usingProfile = true;
-						} catch (UnsatisfiedLinkError e5) {
-							try {
-								Library.loadLibrary ("swt-mozilla18-profile-gcc3"); //$NON-NLS-1$
-								usingProfile = true;
-							} catch (UnsatisfiedLinkError e6) {
-								/* 
-								* fail silently, the Browser will still work without profile support
-								* but will abort any attempts to navigate to HTTPS pages
-								*/
-							}
-						}
-					}
-				}
-			}
-		}
+		//Library.loadLibrary("swt-mozilla17-profile");
+		// We build the profile stuff without the need for a separate DSO
+		usingProfile = true;
 
 		int /*long*/[] retVal = new int /*long*/[1];
 		nsEmbedString pathString = new nsEmbedString(mozillaPath);
@@ -218,11 +247,11 @@
 		if (retVal[0] == 0) error(XPCOM.NS_ERROR_NULL_POINTER);
 		
 		nsILocalFile localFile = new nsILocalFile(retVal[0]);
-		rc = XPCOM.NS_InitEmbedding(localFile.getAddress(), 0);
+		rc = XPCOM.NS_InitXPCOM3(0, localFile.getAddress(), 0, 0, 0);
 		localFile.Release();
 		if (rc != XPCOM.NS_OK) {
 			dispose();
-			SWT.error(SWT.ERROR_NO_HANDLES, null, " [NS_InitEmbedding "+mozillaPath+" error "+rc+"]"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
+			SWT.error(SWT.ERROR_NO_HANDLES, null, " [NS_InitXPCOM3 "+mozillaPath+" error "+rc+"]"); //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
 		}
 
 		rc = XPCOM.NS_GetComponentManager(result);
@@ -283,7 +312,7 @@
 			rc = properties.Get(buffer, nsIFile.NS_IFILE_IID, result);
 			if (rc != XPCOM.NS_OK) error(rc);
 			if (result[0] == 0) error(XPCOM.NS_NOINTERFACE);
-			properties.Release();
+			// properties.Release() is now after the Set below
 
 			nsIFile profileDir = new nsIFile(result[0]);
 			result[0] = 0;
@@ -305,24 +334,15 @@
 			pathString.dispose(); //
 
 			profileDir = new nsIFile(result[0]);
-			result[0] = 0;
-
-			rc = XPCOM_PROFILE.NS_NewProfileDirServiceProvider(true, result);
+			
+			// Set the profile dir property so that it's initialized for
+			// things like password manager and https
+			buffer = Converter.wcsToMbcs(null, XPCOM.NS_APP_USER_PROFILE_50_DIR, true);
+			rc = properties.Set(buffer, profileDir.getAddress());
 			if (rc != XPCOM.NS_OK) error(rc);
-			if (result[0] == 0) error(XPCOM.NS_NOINTERFACE);
-
-			final int /*long*/ dirServiceProvider = result[0];
+			properties.Release();
+						
 			result[0] = 0;
-			rc = XPCOM_PROFILE.ProfileDirServiceProvider_Register(dirServiceProvider);
-			if (rc != XPCOM.NS_OK) error(rc);
-			rc = XPCOM_PROFILE.ProfileDirServiceProvider_SetProfileDir(dirServiceProvider, profileDir.getAddress());
-			if (rc != XPCOM.NS_OK) error(rc);
-
-			getDisplay().addListener(SWT.Dispose, new Listener() {
-				public void handleEvent(Event e) {
-					XPCOM_PROFILE.ProfileDirServiceProvider_Shutdown(dirServiceProvider);
-				}
-			});
 		}
 
 		/*
