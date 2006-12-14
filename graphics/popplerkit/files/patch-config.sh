--- config.sh.orig	Wed Jul 20 22:05:22 2005
+++ config.sh	Sat Jan 21 09:02:31 2006
@@ -50,13 +50,21 @@
    FT_LIBS=`${FT_CONFIG} --libs`
 fi
 
+${PKG_CONFIG} --exists fontconfig
+if [ $? -eq 0 ]; then
+   FC_CFLAGS=`${PKG_CONFIG} --cflags fontconfig`
+   FC_LIBS=`${PKG_CONFIG} --libs fontconfig`
+fi
+
 # write config.make
 echo "# config.make, generated at `date`" >config.make
 echo "POPPLER_CFLAGS=${POPPLER_CFLAGS}" >>config.make
 echo "POPPLER_LIBS=${POPPLER_LIBS}" >>config.make
 echo "FT_CFLAGS=${FT_CFLAGS}" >> config.make
 echo "FT_LIBS=${FT_LIBS}" >> config.make
-echo "ADDITIONAL_CFLAGS=\$(POPPLER_CFLAGS) \$(FT_CFLAGS)" >> config.make
+echo "FC_CFLAGS=${FC_CFLAGS}" >> config.make
+echo "FC_LIBS=${FC_LIBS}" >> config.make
+echo "ADDITIONAL_CFLAGS=\$(POPPLER_CFLAGS) \$(FT_CFLAGS) \$(FC_CFLAGS)" >> config.make
 echo "ADDITIONAL_LDFLAGS=\$(POPPLER_LIBS) \$(POPPLER_LIBS)" >> config.make
 echo "HAVE_CAIRO=${HAVE_CAIRO}" >>config.make
 
