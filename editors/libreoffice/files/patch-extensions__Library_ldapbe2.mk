--- ./extensions/Library_ldapbe2.mk.orig	2013-01-31 05:54:53.000000000 -0500
+++ ./extensions/Library_ldapbe2.mk	2013-02-19 17:56:48.000000000 -0500
@@ -58,16 +58,10 @@
 	wldap32 \
 ))
 else # 0S!=WNT
-$(eval $(call gb_Library_use_externals,ldapbe2,openldap))
-
-$(eval $(call gb_Library_add_libs,ldapbe2,\
-	-lssl3 \
-	-lsmime3 \
-	-lnss3 \
-	-lnssutil3 \
-	-lplds4 \
-	-lplc4 \
-	-lnspr4 \
+$(eval $(call gb_Library_use_externals,ldapbe2,\
+	nss3 \
+	openldap \
+	plc4 \
 ))
 endif
 
