--- server/plugins/gdasspatialstereo.c.orig	Thu Nov  6 21:09:55 2003
+++ server/plugins/gdasspatialstereo.c	Thu Nov  6 21:12:59 2003
@@ -54,9 +54,9 @@
 				(GtkObject* object, GdamArg* arg)	\
 {									\
 	GdasSpatialStereo* spatial = GDAS_SPATIAL_STEREO(object);	\
-	spatial->##prefix##_x = GDAM_ARG_DOUBLE_ARRAY(arg).array[0];	\
-	spatial->##prefix##_y = GDAM_ARG_DOUBLE_ARRAY(arg).array[1];	\
-	spatial->##prefix##_z = GDAM_ARG_DOUBLE_ARRAY(arg).array[2];	\
+	spatial->/**/prefix##_x = GDAM_ARG_DOUBLE_ARRAY(arg).array[0];	\
+	spatial->/**/prefix##_y = GDAM_ARG_DOUBLE_ARRAY(arg).array[1];	\
+	spatial->/**/prefix##_z = GDAM_ARG_DOUBLE_ARRAY(arg).array[2];	\
 }									\
 									\
 static void gdam_spatial_arg_get_##arg_name				\
@@ -65,9 +65,9 @@
 	GdasSpatialStereo* spatial = GDAS_SPATIAL_STEREO(object);	\
 	GDAM_ARG_DOUBLE_ARRAY(arg).length = 3;				\
 	GDAM_ARG_DOUBLE_ARRAY(arg).array = g_new(double, 3);		\
-	GDAM_ARG_DOUBLE_ARRAY(arg).array[0] = spatial->##prefix##_x;	\
-	GDAM_ARG_DOUBLE_ARRAY(arg).array[1] = spatial->##prefix##_y;	\
-	GDAM_ARG_DOUBLE_ARRAY(arg).array[2] = spatial->##prefix##_z;	\
+	GDAM_ARG_DOUBLE_ARRAY(arg).array[0] = spatial->/**/prefix##_x;	\
+	GDAM_ARG_DOUBLE_ARRAY(arg).array[1] = spatial->/**/prefix##_y;	\
+	GDAM_ARG_DOUBLE_ARRAY(arg).array[2] = spatial->/**/prefix##_z;	\
 }
 
 define_set_and_get(left_ear,       lear)
