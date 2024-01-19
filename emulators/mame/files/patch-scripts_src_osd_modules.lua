 Enable the build to find Qt-6.

--- scripts/src/osd/modules.lua.orig	2023-10-23 15:53:41 UTC
+++ scripts/src/osd/modules.lua
@@ -378,7 +378,7 @@ function qtdebuggerbuild()
 			MOC = "moc"
 		else
 			if _OPTIONS["QT_HOME"]~=nil then
-				MOCTST = backtick(_OPTIONS["QT_HOME"] .. "/bin/moc --version 2>/dev/null")
+				MOCTST = backtick(_OPTIONS["QT_HOME"] .. "/libexec/qt6/moc --version 2>/dev/null")
 				if (MOCTST=='') then
 					MOCTST = backtick(_OPTIONS["QT_HOME"] .. "/libexec/moc --version 2>/dev/null")
 					if (MOCTST=='') then
@@ -388,7 +388,7 @@ function qtdebuggerbuild()
 						MOC = _OPTIONS["QT_HOME"] .. "/libexec/moc"
 					end
 				else
-					MOC = _OPTIONS["QT_HOME"] .. "/bin/moc"
+					MOC = _OPTIONS["QT_HOME"] .. "/libexec/qt6/moc"
 				end
 			else
 				MOCTST = backtick("which moc-qt5 2>/dev/null")
@@ -430,7 +430,7 @@ function qtdebuggerbuild()
 		else
 			if _OPTIONS["QT_HOME"]~=nil then
 				buildoptions {
-					"-I" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake -query QT_INSTALL_HEADERS"),
+					"-I" .. backtick(_OPTIONS["QT_HOME"] .. "/bin/qmake6 -query QT_INSTALL_HEADERS"),
 				}
 			else
 				buildoptions {
@@ -500,9 +500,9 @@ function osdmodulestargetconf()
 			}
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
