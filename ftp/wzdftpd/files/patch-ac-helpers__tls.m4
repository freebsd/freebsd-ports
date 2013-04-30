--- ac-helpers/tls.m4.orig
+++ ac-helpers/tls.m4
@@ -22,7 +22,7 @@
   )
 
 if test "$gnutls" = "yes"; then
-AM_PATH_LIBGNUTLS(0.9.8,wzd_have_gnutls=yes)
+PKG_CHECK_MODULES(LIBGNUTLS, [gnutls], [wzd_have_gnutls=yes], [wzd_have_gnutls=no])
 fi
 
 # openssl is checked only if gnutls was not found or disabled
