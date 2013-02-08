--- ./RepositoryExternal.mk.orig	2013-02-01 13:12:08.000000000 -0500
+++ ./RepositoryExternal.mk	2013-02-01 13:37:47.000000000 -0500
@@ -1056,7 +1056,7 @@
 )
 
 $(call gb_LinkTarget_add_libs,$(1),\
-	-l$(DB_LIB) \
+	$(DB_LIB) \
 )
 
 endef
