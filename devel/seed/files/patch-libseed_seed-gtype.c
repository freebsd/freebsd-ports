--- libseed/seed-gtype.c.orig	2010-08-30 21:37:38.000000000 +0000
+++ libseed/seed-gtype.c	2012-02-07 15:33:05.000000000 +0000
@@ -1032,9 +1032,6 @@
 
   proto = seed_struct_prototype (ctx, objectclass_info);
 
-  paramspec_info = g_irepository_find_by_name (NULL, "GObject", "ParamSpec");
-  proto = seed_struct_prototype (ctx, paramspec_info);
-
   seed_create_function (ctx, "get", &seed_param_getter_invoked, proto);
   seed_create_function (ctx, "set", &seed_param_setter_invoked, proto);
 }
