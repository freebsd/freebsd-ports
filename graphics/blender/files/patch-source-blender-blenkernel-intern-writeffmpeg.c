--- source/blender/blenkernel/intern/writeffmpeg.c.orig	2011-06-24 09:07:48.320613989 +0200
+++ source/blender/blenkernel/intern/writeffmpeg.c	2011-06-24 09:08:17.697825516 +0200
@@ -1101,12 +1101,12 @@
 	switch (o->type) {
 	case FF_OPT_TYPE_INT:
 	case FF_OPT_TYPE_INT64:
-		val.i = o->default_val;
+		val.i = o->default_val.i64;
 		idp_type = IDP_INT;
 		break;
 	case FF_OPT_TYPE_DOUBLE:
 	case FF_OPT_TYPE_FLOAT:
-		val.f = o->default_val;
+		val.f = o->default_val.dbl;
 		idp_type = IDP_FLOAT;
 		break;
 	case FF_OPT_TYPE_STRING:
