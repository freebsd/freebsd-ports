--- acinclude.m4.orig	2021-08-07 13:54:37 UTC
+++ acinclude.m4
@@ -601,10 +601,7 @@ dnl Incorporate Freetype2.
 dnl AC_INCORPORATE_FREETYPE2([version], [define on found], [obligatory])
 AC_DEFUN([AC_INCORPORATE_FREETYPE2],
 [
-	AC_CHECK_FT2([$1],
-		freetype2=[yes],
-		freetype2=[no])
-	AC_INCORPORATE([Freetype2], [$freetype2], [$FT2_CFLAGS], [$FT2_LIBS], [$2], [$3])
+	AC_INCORPORATE_PKGCONFIG([freetype2],[$1],[$2],[no])
 ])
 
 dnl Incorporate GLEW.
