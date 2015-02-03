--- configure.ac.orig	2015-01-29 19:58:01.271153231 +0100
+++ configure.ac	2015-01-29 19:58:25.237151226 +0100
@@ -593,6 +593,11 @@
 	AC_DEFINE(POPPLER_EVEN_NEWER_COLOR_SPACE_API, 1, [Use even newer color space API from Poppler >= 0.26.0])
 fi
 
+PKG_CHECK_MODULES(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API, poppler >= 0.29.0, popplernewernewcolorspaceapi=yes, popplernewernewcolorspaceapi=no)
+if test "x$popplernewernewcolorspaceapi" = "xyes"; then
+	AC_DEFINE(POPPLER_EVEN_NEWER_NEW_COLOR_SPACE_API, 1, [Use even newer new color space API from Poppler >= 0.29.0])
+fi
+
 # Poppler's b604a008 commit changes this
 AC_MSG_CHECKING([whether Poppler's GfxPatch no longer uses GfxColor])
 popplergfxcolor="no"
