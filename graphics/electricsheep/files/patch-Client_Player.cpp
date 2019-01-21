--- Client/Player.cpp.orig	2018-07-14 21:10:29 UTC
+++ Client/Player.cpp
@@ -14,7 +14,7 @@
 #include	"GLee.h"
 #else
 #include <GLee.h>
-#include <endian.h>
+#include <sys/endian.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN__ __LITTLE_ENDIAN
 #undef __BIG_ENDIAN__
@@ -331,7 +331,7 @@ bool	CPlayer::Startup()
 #ifndef LINUX_GNU
 	std::string	scriptRoot = g_Settings()->Get( "settings.app.InstallDir", std::string("./") ) + "Scripts";
 #else
-	std::string	scriptRoot = g_Settings()->Get( "settings.app.InstallDir", std::string(SHAREDIR) ) + "Scripts";
+	std::string	scriptRoot = g_Settings()->Get( "settings.app.InstallDir", std::string(SHAREDIR) ) + "/Scripts";
 #endif
 	std::string watchFolder = g_Settings()->Get( "settings.content.sheepdir", content ) + "/mpeg/";
 
