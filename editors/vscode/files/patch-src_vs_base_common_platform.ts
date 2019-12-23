--- src/vs/base/common/platform.ts.orig	2019-12-10 21:16:00 UTC
+++ src/vs/base/common/platform.ts
@@ -55,14 +55,14 @@ if (typeof navigator === 'object' && !isElectronRender
 	_isWindows = _userAgent.indexOf('Windows') >= 0;
 	_isMacintosh = _userAgent.indexOf('Macintosh') >= 0;
 	_isIOS = _userAgent.indexOf('Macintosh') >= 0 && !!navigator.maxTouchPoints && navigator.maxTouchPoints > 0;
-	_isLinux = _userAgent.indexOf('Linux') >= 0;
+	_isLinux = _userAgent.indexOf('Linux') >= 0 || _userAgent.indexOf('FreeBSD') >= 0;
 	_isWeb = true;
 	_locale = navigator.language;
 	_language = _locale;
 } else if (typeof process === 'object') {
 	_isWindows = (process.platform === 'win32');
 	_isMacintosh = (process.platform === 'darwin');
-	_isLinux = (process.platform === 'linux');
+	_isLinux = (process.platform === 'linux' || process.platform === 'freebsd');
 	_locale = LANGUAGE_DEFAULT;
 	_language = LANGUAGE_DEFAULT;
 	const rawNlsConfig = process.env['VSCODE_NLS_CONFIG'];
