 Enable the build to find Qt-6.

--- scripts/src/osd/modules.lua.orig	2025-09-24 14:56:11 UTC
+++ scripts/src/osd/modules.lua
@@ -405,7 +405,7 @@ function qtdebuggerbuild()
 			MOC = "moc"
 		else
 			if _OPTIONS["QT_HOME"]~=nil then
-				local MOCTST = backtick(_OPTIONS["QT_HOME"] .. "/bin/moc --version 2>/dev/null")
+				local MOCTST = backtick(_OPTIONS["QT_HOME"] .. "/libexec/qt6/moc --version 2>/dev/null")
 				if MOCTST=='' then
 					local qt_host_libexecs = backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake -query QT_HOST_LIBEXECS")
 					if not string.starts(qt_host_libexecs,"/") then
@@ -419,7 +419,7 @@ function qtdebuggerbuild()
 						MOC = qt_host_libexecs .. "/moc"
 					end
 				else
-					MOC = _OPTIONS["QT_HOME"] .. "/bin/moc"
+					MOC = _OPTIONS["QT_HOME"] .. "/libexec/qt6/moc"
 				end
 			else
 				local MOCTST = backtick("which moc-qt5 2>/dev/null")
@@ -461,7 +461,7 @@ function qtdebuggerbuild()
 		else
 			if _OPTIONS["QT_HOME"]~=nil then
 				buildoptions {
-					"-I" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake -query QT_INSTALL_HEADERS"),
+					"-I" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake6 -query QT_INSTALL_HEADERS"),
 				}
 			else
 				buildoptions {
@@ -540,9 +540,9 @@ function osdmodulestargetconf()
 			end
 		else
 			if _OPTIONS["QT_HOME"]~=nil then
-				local qt_version = str_to_version(backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake -query QT_VERSION"))
+				local qt_version = str_to_version(backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake6 -query QT_VERSION"))
 				linkoptions {
-					"-L" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake -query QT_INSTALL_LIBS"),
+					"-L" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake6 -query QT_INSTALL_LIBS"),
 				}
 				if qt_version < 60000 then
 					links {
