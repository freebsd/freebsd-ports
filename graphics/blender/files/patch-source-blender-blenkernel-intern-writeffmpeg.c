--- source/blender/blenkernel/intern/writeffmpeg.c.orig	2011-06-26 11:28:46.000000000 +0200
+++ source/blender/blenkernel/intern/writeffmpeg.c	2011-06-26 11:29:27.000000000 +0200
@@ -1053,12 +1053,12 @@
 	switch (o->type) {
 	case FF_OPT_TYPE_INT:
 	case FF_OPT_TYPE_INT64:
-		val.i = FFMPEG_DEF_OPT_VAL_INT(o);
+		val.i = o->default_val.i64;
 		idp_type = IDP_INT;
 		break;
 	case FF_OPT_TYPE_DOUBLE:
 	case FF_OPT_TYPE_FLOAT:
-		val.f = FFMPEG_DEF_OPT_VAL_DOUBLE(o);
+		val.f = o->default_val.dbl;
 		idp_type = IDP_FLOAT;
 		break;
 	case FF_OPT_TYPE_STRING:
