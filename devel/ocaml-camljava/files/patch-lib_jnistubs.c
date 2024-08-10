--- lib/jnistubs.c.orig	2024-06-03 17:46:36 UTC
+++ lib/jnistubs.c
@@ -53,10 +53,10 @@ static value alloc_jobject(jobject obj)
 
 static value alloc_jobject(jobject obj)
 {
-  value v = alloc_custom(&jobject_ops, sizeof(jobject), 0, 1);
+  value v = caml_alloc_custom(&jobject_ops, sizeof(jobject), 0, 1);
   if (obj != NULL) {
     obj = (*jenv)->NewGlobalRef(jenv, obj);
-    if (obj == NULL) raise_out_of_memory();
+    if (obj == NULL) caml_raise_out_of_memory();
   }
   JObject(v) = obj;
   return v;
@@ -98,11 +98,11 @@ static void check_java_exception(void)
     if (camljava_raise_exception == NULL) {
       camljava_raise_exception = caml_named_value("camljava_raise_exception");
       if (camljava_raise_exception == NULL)
-        invalid_argument("Java_lang not linked in");
+        caml_invalid_argument("Java_lang not linked in");
     }
     vobj = alloc_jobject(exn);
     (*jenv)->DeleteLocalRef(jenv, exn);
-    callback(*camljava_raise_exception, vobj);
+    caml_callback(*camljava_raise_exception, vobj);
   }
 }
 
@@ -113,9 +113,9 @@ static void check_non_null(value jobj)
   if (camljava_null_pointer == NULL) {
     camljava_null_pointer = caml_named_value("camljava_null_pointer");
     if (camljava_null_pointer == NULL)
-      invalid_argument("Java not linked in");
+      caml_invalid_argument("Java not linked in");
   }
-  raise_constant(*camljava_null_pointer);
+  caml_raise_constant(*camljava_null_pointer);
 }
 
 /*********** Class operations ************/
@@ -147,7 +147,7 @@ static value alloc_jfieldID(jfieldID id)
 
 static value alloc_jfieldID(jfieldID id)
 {
-  value v = alloc((sizeof(jfieldID) + sizeof(value) - 1) / sizeof(value),
+  value v = caml_alloc((sizeof(jfieldID) + sizeof(value) - 1) / sizeof(value),
                   Abstract_tag);
   JField(v) = id;
   return v;
@@ -185,10 +185,10 @@ GETFIELD(GetShortField, jshort, Val_int)
 GETFIELD(GetByteField, jbyte, Val_int)
 GETFIELD(GetCharField, jchar, Val_int)
 GETFIELD(GetShortField, jshort, Val_int)
-GETFIELD(GetIntField, jint, copy_int32)
-GETFIELD(GetLongField, jlong, copy_int64)
-GETFIELD(GetFloatField, jfloat, copy_double)
-GETFIELD(GetDoubleField, jdouble, copy_double)
+GETFIELD(GetIntField, jint, caml_copy_int32)
+GETFIELD(GetLongField, jlong, caml_copy_int64)
+GETFIELD(GetFloatField, jfloat, caml_copy_double)
+GETFIELD(GetDoubleField, jdouble, caml_copy_double)
 
 value camljava_GetCamlintField(value vobj, value vfield)
 {
@@ -237,10 +237,10 @@ GETSTATICFIELD(GetStaticShortField, jshort, Val_int)
 GETSTATICFIELD(GetStaticByteField, jbyte, Val_int)
 GETSTATICFIELD(GetStaticCharField, jchar, Val_int)
 GETSTATICFIELD(GetStaticShortField, jshort, Val_int)
-GETSTATICFIELD(GetStaticIntField, jint, copy_int32)
-GETSTATICFIELD(GetStaticLongField, jlong, copy_int64)
-GETSTATICFIELD(GetStaticFloatField, jfloat, copy_double)
-GETSTATICFIELD(GetStaticDoubleField, jdouble, copy_double)
+GETSTATICFIELD(GetStaticIntField, jint, caml_copy_int32)
+GETSTATICFIELD(GetStaticLongField, jlong, caml_copy_int64)
+GETSTATICFIELD(GetStaticFloatField, jfloat, caml_copy_double)
+GETSTATICFIELD(GetStaticDoubleField, jdouble, caml_copy_double)
 
 value camljava_GetStaticCamlintField(value vclass, value vfield)
 {
@@ -279,7 +279,7 @@ static value alloc_jmethodID(jmethodID id)
 
 static value alloc_jmethodID(jmethodID id)
 {
-  value v = alloc((sizeof(jmethodID) + sizeof(value) - 1) / sizeof(value),
+  value v = caml_alloc((sizeof(jmethodID) + sizeof(value) - 1) / sizeof(value),
                   Abstract_tag);
   JMethod(v) = id;
   return v;
@@ -344,7 +344,7 @@ static jvalue * convert_args(value vargs, jvalue defau
   if (nargs <= NUM_DEFAULT_ARGS)
     args = default_args;
   else
-    args = stat_alloc(nargs * sizeof(jvalue));
+    args = caml_stat_alloc(nargs * sizeof(jvalue));
   for (i = 0; i < nargs; i++) jvalue_val(Field(vargs, i), &(args[i]));
   return args;
 }
@@ -360,7 +360,7 @@ value camljava_##callname(value vobj, value vmeth, val
   check_non_null(vobj);                                                     \
   args = convert_args(vargs, default_args);                                 \
   res = (*jenv)->callname##A(jenv, JObject(vobj), JMethod(vmeth), args);    \
-  if (args != default_args) stat_free(args);                                \
+  if (args != default_args) caml_stat_free(args);                                \
   check_java_exception();                                                   \
   return resconv(res);                                                      \
 }
@@ -370,10 +370,10 @@ CALLMETHOD(CallShortMethod, jshort, Val_int)
 CALLMETHOD(CallByteMethod, jbyte, Val_int)
 CALLMETHOD(CallCharMethod, jchar, Val_int)
 CALLMETHOD(CallShortMethod, jshort, Val_int)
-CALLMETHOD(CallIntMethod, jint, copy_int32)
-CALLMETHOD(CallLongMethod, jlong, copy_int64)
-CALLMETHOD(CallFloatMethod, jfloat, copy_double)
-CALLMETHOD(CallDoubleMethod, jdouble, copy_double)
+CALLMETHOD(CallIntMethod, jint, caml_copy_int32)
+CALLMETHOD(CallLongMethod, jlong, caml_copy_int64)
+CALLMETHOD(CallFloatMethod, jfloat, caml_copy_double)
+CALLMETHOD(CallDoubleMethod, jdouble, caml_copy_double)
 
 value camljava_CallCamlintMethod(value vobj, value vmeth, value vargs)
 {
@@ -383,7 +383,7 @@ value camljava_CallCamlintMethod(value vobj, value vme
   check_non_null(vobj);
   args = convert_args(vargs, default_args);
   res = (*jenv)->CallIntMethodA(jenv, JObject(vobj), JMethod(vmeth), args);
-  if (args != default_args) stat_free(args);
+  if (args != default_args) caml_stat_free(args);
   check_java_exception();
   return Val_int(res);
 }
@@ -395,7 +395,7 @@ value camljava_CallVoidMethod(value vobj, value vmeth,
   check_non_null(vobj);
   args = convert_args(vargs, default_args);
   (*jenv)->CallVoidMethodA(jenv, JObject(vobj), JMethod(vmeth), args);
-  if (args != default_args) stat_free(args);
+  if (args != default_args) caml_stat_free(args);
   check_java_exception();
   return Val_unit;
 }
@@ -407,7 +407,7 @@ value camljava_##callname(value vclass, value vmeth, v
   jvalue * args = convert_args(vargs, default_args);                        \
   restyp res =                                                              \
     (*jenv)->callname##A(jenv, JObject(vclass), JMethod(vmeth), args);      \
-  if (args != default_args) stat_free(args);                                \
+  if (args != default_args) caml_stat_free(args);                                \
   check_java_exception();                                                   \
   return resconv(res);                                                      \
 }
@@ -417,10 +417,10 @@ CALLSTATICMETHOD(CallStaticShortMethod, jshort, Val_in
 CALLSTATICMETHOD(CallStaticByteMethod, jbyte, Val_int)
 CALLSTATICMETHOD(CallStaticCharMethod, jchar, Val_int)
 CALLSTATICMETHOD(CallStaticShortMethod, jshort, Val_int)
-CALLSTATICMETHOD(CallStaticIntMethod, jint, copy_int32)
-CALLSTATICMETHOD(CallStaticLongMethod, jlong, copy_int64)
-CALLSTATICMETHOD(CallStaticFloatMethod, jfloat, copy_double)
-CALLSTATICMETHOD(CallStaticDoubleMethod, jdouble, copy_double)
+CALLSTATICMETHOD(CallStaticIntMethod, jint, caml_copy_int32)
+CALLSTATICMETHOD(CallStaticLongMethod, jlong, caml_copy_int64)
+CALLSTATICMETHOD(CallStaticFloatMethod, jfloat, caml_copy_double)
+CALLSTATICMETHOD(CallStaticDoubleMethod, jdouble, caml_copy_double)
 
 value camljava_CallStaticCamlintMethod(value vclass, value vmeth, value vargs)
 {
@@ -428,7 +428,7 @@ value camljava_CallStaticCamlintMethod(value vclass, v
   jvalue * args = convert_args(vargs, default_args);
   jint res =
     (*jenv)->CallStaticIntMethodA(jenv, JObject(vclass), JMethod(vmeth), args);
-  if (args != default_args) stat_free(args);
+  if (args != default_args) caml_stat_free(args);
   check_java_exception();
   return Val_int(res);
 }
@@ -438,7 +438,7 @@ value camljava_CallStaticVoidMethod(value vclass, valu
   jvalue default_args[NUM_DEFAULT_ARGS];
   jvalue * args = convert_args(vargs, default_args);
   (*jenv)->CallStaticVoidMethodA(jenv, JObject(vclass), JMethod(vmeth), args);
-  if (args != default_args) stat_free(args);
+  if (args != default_args) caml_stat_free(args);
   check_java_exception();
   return Val_unit;
 }
@@ -453,7 +453,7 @@ value camljava_##callname(value vobj, value vclass, va
   args = convert_args(vargs, default_args);                                 \
   res = (*jenv)->callname##A(jenv, JObject(vobj), JObject(vclass),          \
                              JMethod(vmeth), args);                         \
-  if (args != default_args) stat_free(args);                                \
+  if (args != default_args) caml_stat_free(args);                                \
   check_java_exception();                                                   \
   return resconv(res);                                                      \
 }
@@ -463,10 +463,10 @@ CALLNONVIRTUALMETHOD(CallNonvirtualShortMethod, jshort
 CALLNONVIRTUALMETHOD(CallNonvirtualByteMethod, jbyte, Val_int)
 CALLNONVIRTUALMETHOD(CallNonvirtualCharMethod, jchar, Val_int)
 CALLNONVIRTUALMETHOD(CallNonvirtualShortMethod, jshort, Val_int)
-CALLNONVIRTUALMETHOD(CallNonvirtualIntMethod, jint, copy_int32)
-CALLNONVIRTUALMETHOD(CallNonvirtualLongMethod, jlong, copy_int64)
-CALLNONVIRTUALMETHOD(CallNonvirtualFloatMethod, jfloat, copy_double)
-CALLNONVIRTUALMETHOD(CallNonvirtualDoubleMethod, jdouble, copy_double)
+CALLNONVIRTUALMETHOD(CallNonvirtualIntMethod, jint, caml_copy_int32)
+CALLNONVIRTUALMETHOD(CallNonvirtualLongMethod, jlong, caml_copy_int64)
+CALLNONVIRTUALMETHOD(CallNonvirtualFloatMethod, jfloat, caml_copy_double)
+CALLNONVIRTUALMETHOD(CallNonvirtualDoubleMethod, jdouble, caml_copy_double)
 
 value camljava_CallNonvirtualCamlintMethod(value vobj, value vclass,
                                            value vmeth, value vargs)
@@ -478,7 +478,7 @@ value camljava_CallNonvirtualCamlintMethod(value vobj,
   args = convert_args(vargs, default_args);
   res = (*jenv)->CallNonvirtualIntMethodA(jenv, JObject(vobj), JObject(vclass),
                                           JMethod(vmeth), args);
-  if (args != default_args) stat_free(args);
+  if (args != default_args) caml_stat_free(args);
   check_java_exception();
   return Val_int(res);
 }
@@ -492,7 +492,7 @@ value camljava_CallNonvirtualVoidMethod(value vobj, va
   args = convert_args(vargs, default_args);
   (*jenv)->CallNonvirtualVoidMethodA(jenv, JObject(vobj), JObject(vclass),
                                      JMethod(vmeth), args);
-  if (args != default_args) stat_free(args);
+  if (args != default_args) caml_stat_free(args);
   check_java_exception();
   return Val_unit;
 }
@@ -507,7 +507,7 @@ value camljava_RegisterNullString(value null_string)
 value camljava_RegisterNullString(value null_string)
 {
   camljava_null_string = null_string;
-  register_global_root(&camljava_null_string);
+  caml_register_global_root(&camljava_null_string);
   return Val_unit;
 }
 
@@ -541,7 +541,7 @@ static value extract_java_string (JNIEnv * env, jstrin
 
   if (jstr == NULL) return camljava_null_string;
   len = (*env)->GetStringUTFLength(env, jstr);
-  res = alloc_string(len);
+  res = caml_alloc_string(len);
   chrs = (*env)->GetStringUTFChars(env, jstr, &isCopy);
   memcpy(String_val(res), chrs, len);
   (*env)->ReleaseStringUTFChars(env, jstr, chrs);
@@ -630,10 +630,10 @@ ARRAYNEWGETSET(Short, jshortArray, jshort, Int_val, Va
 ARRAYNEWGETSET(Byte, jbyteArray, jbyte, Int_val, Val_int)
 ARRAYNEWGETSET(Char, jcharArray, jchar, Int_val, Val_int)
 ARRAYNEWGETSET(Short, jshortArray, jshort, Int_val, Val_int)
-ARRAYNEWGETSET(Int, jintArray, jint, Int32_val, copy_int32)
-ARRAYNEWGETSET(Long, jlongArray, jlong, Int64_val, copy_int64)
-ARRAYNEWGETSET(Float, jfloatArray, jfloat, Double_val, copy_double)
-ARRAYNEWGETSET(Double, jdoubleArray, jdouble, Double_val, copy_double)
+ARRAYNEWGETSET(Int, jintArray, jint, Int32_val, caml_copy_int32)
+ARRAYNEWGETSET(Long, jlongArray, jlong, Int64_val, caml_copy_int64)
+ARRAYNEWGETSET(Float, jfloatArray, jfloat, Double_val, caml_copy_double)
+ARRAYNEWGETSET(Double, jdoubleArray, jdouble, Double_val, caml_copy_double)
 
 value camljava_GetCamlintArrayElement(value varray, value vidx)
 {
@@ -665,8 +665,8 @@ value camljava_GetByteArrayRegion(value varray, value 
   long length = Long_val(vlength);
 
   check_non_null(varray);
-  if (dstidx < 0 || length < 0 || dstidx + length > string_length(vstr))
-    invalid_argument("Jni.get_byte_array_region");
+  if (dstidx < 0 || length < 0 || dstidx + length > caml_string_length(vstr))
+    caml_invalid_argument("Jni.get_byte_array_region");
   (*jenv)->GetByteArrayRegion(jenv, (jbyteArray) JObject(varray),
                               srcidx, length, (jbyte *) &Byte(vstr, dstidx));
   check_java_exception();
@@ -682,8 +682,8 @@ value camljava_SetByteArrayRegion(value vstr, value vs
   long length = Long_val(vlength);
 
   check_non_null(varray);
-  if (srcidx < 0 || length < 0 || srcidx + length > string_length(vstr))
-    invalid_argument("Jni.set_byte_array_region");
+  if (srcidx < 0 || length < 0 || srcidx + length > caml_string_length(vstr))
+    caml_invalid_argument("Jni.set_byte_array_region");
   (*jenv)->SetByteArrayRegion(jenv, (jbyteArray) JObject(varray),
                               dstidx, length, (jbyte *) &Byte(vstr, srcidx));
   check_java_exception();
@@ -702,7 +702,7 @@ value camljava_Init(value vclasspath)
 
   /* Set the class path */
   classpath = 
-    stat_alloc(strlen(setclasspath) + string_length(vclasspath) + 1);
+    caml_stat_alloc(strlen(setclasspath) + caml_string_length(vclasspath) + 1);
   strcpy(classpath, setclasspath);
   strcat(classpath, String_val(vclasspath));
   options[0].optionString = classpath;
@@ -712,8 +712,8 @@ value camljava_Init(value vclasspath)
   vm_args.ignoreUnrecognized = 1;
   /* Load and initialize a Java VM, return a JNI interface pointer in env */
   retcode = JNI_CreateJavaVM(&jvm, (void **) &jenv, &vm_args);
-  stat_free(classpath);
-  if (retcode < 0) failwith("Java.init");
+  caml_stat_free(classpath);
+  if (retcode < 0) caml_failwith("Java.init");
   init_threading(); // by O'Jacare
   return Val_unit;
 }
@@ -856,17 +856,17 @@ static value camljava_callback(JNIEnv * env,
       else if ((*env)->IsInstanceOf(env, arg, caml_short))
         carg = Val_int((*env)->GetShortField(env, arg, caml_short_contents));
       else if ((*env)->IsInstanceOf(env, arg, caml_int))
-        carg = copy_int32((*env)->GetIntField(env, arg, caml_int_contents));
+        carg = caml_copy_int32((*env)->GetIntField(env, arg, caml_int_contents));
       else if ((*env)->IsInstanceOf(env, arg, caml_camlint))
         carg = Val_int((*env)->GetIntField(env, arg, caml_camlint_contents));
       else if ((*env)->IsInstanceOf(env, arg, caml_long))
-        carg = copy_int64((*env)->GetLongField(env, arg,
+        carg = caml_copy_int64((*env)->GetLongField(env, arg,
                                                caml_long_contents));
       else if ((*env)->IsInstanceOf(env, arg, caml_float))
-        carg = copy_double((*env)->GetFloatField(env, arg,
+        carg = caml_copy_double((*env)->GetFloatField(env, arg,
                                                  caml_float_contents));
       else if ((*env)->IsInstanceOf(env, arg, caml_double))
-        carg = copy_double((*env)->GetDoubleField(env, arg,
+        carg = caml_copy_double((*env)->GetDoubleField(env, arg,
                                                 caml_double_contents));
       else if (string_auto_conv
 	       && (*env)->IsInstanceOf(env, arg, java_lang_string))
@@ -877,7 +877,7 @@ static value camljava_callback(JNIEnv * env,
     }
   End_roots();
   clos = caml_get_public_method(cargs[0], (value) method_id);
-  res = callbackN_exn(clos, n, cargs);
+  res = caml_callbackN_exn(clos, n, cargs);
   free(cargs);
   jenv = savedenv;
   return res;
@@ -928,17 +928,17 @@ value camljava_WrapCamlObject(value vobj)
 
 value camljava_WrapCamlObject(value vobj)
 {
-  value * wrapper = stat_alloc(sizeof(value));
+  value * wrapper = caml_stat_alloc(sizeof(value));
   *wrapper = vobj;
-  register_global_root(wrapper);
-  return copy_int64((jlong) (value) wrapper);
+  caml_register_global_root(wrapper);
+  return caml_copy_int64((jlong) (value) wrapper);
 }
 
 void camljava_FreeWrapper(JNIEnv * env, jclass cls, jlong wrapper)
 {
   value * w = (value *) (value) wrapper;
-  remove_global_root(w);
-  stat_free(w);
+  caml_remove_global_root(w);
+  caml_stat_free(w);
 }
 
 jlong camljava_GetCamlMethodID(JNIEnv * env, jclass cls, jstring jname)
