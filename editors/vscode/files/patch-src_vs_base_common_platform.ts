--- src/vs/base/common/platform.ts.orig	2023-12-06 10:36:56 UTC
+++ src/vs/base/common/platform.ts
@@ -81,7 +81,7 @@ if (typeof navigator === 'object' && !isElectronRender
 	_isWindows = _userAgent.indexOf('Windows') >= 0;
 	_isMacintosh = _userAgent.indexOf('Macintosh') >= 0;
 	_isIOS = (_userAgent.indexOf('Macintosh') >= 0 || _userAgent.indexOf('iPad') >= 0 || _userAgent.indexOf('iPhone') >= 0) && !!navigator.maxTouchPoints && navigator.maxTouchPoints > 0;
-	_isLinux = _userAgent.indexOf('Linux') >= 0;
+	_isLinux = (_userAgent.indexOf('Linux') >= 0 || _userAgent.indexOf('FreeBSD') >= 0);
 	_isMobile = _userAgent?.indexOf('Mobi') >= 0;
 	_isWeb = true;
 
@@ -102,7 +102,7 @@ else if (typeof nodeProcess === 'object') {
 else if (typeof nodeProcess === 'object') {
 	_isWindows = (nodeProcess.platform === 'win32');
 	_isMacintosh = (nodeProcess.platform === 'darwin');
-	_isLinux = (nodeProcess.platform === 'linux');
+	_isLinux = (nodeProcess.platform === 'linux' || nodeProcess.platform === 'freebsd');
 	_isLinuxSnap = _isLinux && !!nodeProcess.env['SNAP'] && !!nodeProcess.env['SNAP_REVISION'];
 	_isElectron = isElectronProcess;
 	_isCI = !!nodeProcess.env['CI'] || !!nodeProcess.env['BUILD_ARTIFACTSTAGINGDIRECTORY'];
