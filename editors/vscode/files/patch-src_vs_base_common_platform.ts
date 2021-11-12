--- src/vs/base/common/platform.ts.orig	2021-07-14 21:51:05 UTC
+++ src/vs/base/common/platform.ts
@@ -103,7 +103,7 @@ if (typeof navigator === 'object' && !isElectronRender
 	_isWindows = _userAgent.indexOf('Windows') >= 0;
 	_isMacintosh = _userAgent.indexOf('Macintosh') >= 0;
 	_isIOS = (_userAgent.indexOf('Macintosh') >= 0 || _userAgent.indexOf('iPad') >= 0 || _userAgent.indexOf('iPhone') >= 0) && !!navigator.maxTouchPoints && navigator.maxTouchPoints > 0;
-	_isLinux = _userAgent.indexOf('Linux') >= 0;
+	_isLinux = (_userAgent.indexOf('Linux') >= 0 || _userAgent.indexOf('FreeBSD') >= 0);
 	_isWeb = true;
 	_locale = navigator.language;
 	_language = _locale;
@@ -113,7 +113,7 @@ if (typeof navigator === 'object' && !isElectronRender
 else if (typeof nodeProcess === 'object') {
 	_isWindows = (nodeProcess.platform === 'win32');
 	_isMacintosh = (nodeProcess.platform === 'darwin');
-	_isLinux = (nodeProcess.platform === 'linux');
+	_isLinux = (nodeProcess.platform === 'linux' || nodeProcess.platform === 'freebsd');
 	_isLinuxSnap = _isLinux && !!nodeProcess.env['SNAP'] && !!nodeProcess.env['SNAP_REVISION'];
 	_locale = LANGUAGE_DEFAULT;
 	_language = LANGUAGE_DEFAULT;
