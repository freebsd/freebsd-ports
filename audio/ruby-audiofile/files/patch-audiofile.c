--- audiofile.c.orig	2003-08-09 23:29:57 UTC
+++ audiofile.c
@@ -161,7 +161,7 @@ static VALUE af_initialize(int argc, VAL
 
             /* get mode into a C-string */
             mode = malloc(2);
-            mode[0] = *(RSTRING(v_mode)->ptr);
+            mode[0] = *(RSTRING_PTR(v_mode));
             mode[1] = '\0';
 
             switch(*mode) {
@@ -188,7 +188,7 @@ static VALUE af_initialize(int argc, VAL
     switch(*mode) {
         case 'r':
 
-            fh = afOpenFile(RSTRING(v_fn)->ptr, mode, AF_NULL_FILESETUP);
+            fh = afOpenFile(RSTRING_PTR(v_fn), mode, AF_NULL_FILESETUP);
             if(fh != AF_NULL_FILEHANDLE) {
                 afp = ALLOC(struct af_data);
                 DATA_PTR(obj) = afp;
@@ -212,8 +212,8 @@ static VALUE af_initialize(int argc, VAL
 
         case 'w':
             
-            fn = malloc(RSTRING(v_fn)->len+1);
-            strcpy(fn, RSTRING(v_fn)->ptr);
+            fn = malloc(RSTRING_LEN(v_fn)+1);
+            strcpy(fn, RSTRING_PTR(v_fn));
 
             afp = ALLOC(struct af_data);
             DATA_PTR(obj) = afp;
@@ -335,8 +335,8 @@ static VALUE af_read_into(VALUE obj, VAL
     
 
     Check_Type(readIntoString, T_STRING);
-    bytes = RSTRING(readIntoString)->len;
-    buf = RSTRING(readIntoString)->ptr;
+    bytes = RSTRING_LEN(readIntoString);
+    buf = RSTRING_PTR(readIntoString);
 
     frame_size = afGetFrameSize(afp->handle, AF_DEFAULT_TRACK, EXPAND_3TO4);
     frames = bytes / frame_size;
@@ -357,8 +357,8 @@ static VALUE actually_write(VALUE obj, V
     GetAFP(obj, afp);
 
     Check_Type(writeFromString, T_STRING);
-    bytes = RSTRING(writeFromString)->len;
-    buf = RSTRING(writeFromString)->ptr;
+    bytes = RSTRING_LEN(writeFromString);
+    buf = RSTRING_PTR(writeFromString);
 
     frame_size = afGetFrameSize(afp->handle, AF_DEFAULT_TRACK, EXPAND_3TO4);
     frames = bytes / frame_size;
@@ -679,18 +679,18 @@ static VALUE af_pcm_mapping_eq(VALUE obj
     struct af_data *afp;
 
     Check_Type(args, T_ARRAY);
-    if(RARRAY(args)->len != 1) {
+    if(RARRAY_LEN(args) != 1) {
         rb_raise(rb_eArgError, "incorrect argument(s) to AudioFile#pcm_mapping=");
     }
-    args = *(RARRAY(args)->ptr);
-    if(RARRAY(args)->len != 4) {
+    args = *(RARRAY_PTR(args));
+    if(RARRAY_LEN(args) != 4) {
         rb_raise(rb_eArgError, "incorrect argument(s) to AudioFile#pcm_mapping=");
     }
 
-    v_slope     = RARRAY(args)->ptr[0];
-    v_intercept = RARRAY(args)->ptr[1];
-    v_min_clip  = RARRAY(args)->ptr[2];
-    v_max_clip  = RARRAY(args)->ptr[3];
+    v_slope     = RARRAY_PTR(args)[0];
+    v_intercept = RARRAY_PTR(args)[1];
+    v_min_clip  = RARRAY_PTR(args)[2];
+    v_max_clip  = RARRAY_PTR(args)[3];
     Check_Type(v_slope, T_FLOAT);
     Check_Type(v_intercept, T_FLOAT);
     Check_Type(v_min_clip, T_FLOAT);
@@ -700,12 +700,12 @@ static VALUE af_pcm_mapping_eq(VALUE obj
 
     if(af_is_open(afp)) {
         afSetTrackPCMMapping(afp->handle, AF_DEFAULT_TRACK, 
-                RFLOAT(v_slope)->value, RFLOAT(v_intercept)->value,
-                RFLOAT(v_min_clip)->value, RFLOAT(v_max_clip)->value);
+                RFLOAT_VALUE(v_slope), RFLOAT_VALUE(v_intercept),
+                RFLOAT_VALUE(v_min_clip), RFLOAT_VALUE(v_max_clip));
     } else {
         afInitPCMMapping(afp->setup, AF_DEFAULT_TRACK, 
-                RFLOAT(v_slope)->value, RFLOAT(v_intercept)->value,
-                RFLOAT(v_min_clip)->value, RFLOAT(v_max_clip)->value);
+                RFLOAT_VALUE(v_slope), RFLOAT_VALUE(v_intercept),
+                RFLOAT_VALUE(v_min_clip), RFLOAT_VALUE(v_max_clip));
     }
 
     return Qnil;
