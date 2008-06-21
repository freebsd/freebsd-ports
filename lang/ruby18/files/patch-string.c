--- string.c.orig	2008-06-21 12:38:53.000000000 +0400
+++ string.c	2008-06-21 12:49:20.000000000 +0400
@@ -452,22 +452,16 @@
  */
 
 static VALUE
-rb_str_format(str, arg)
+rb_str_format_m(str, arg)
     VALUE str, arg;
 {
-    VALUE *argv;
+    VALUE tmp = rb_check_array_type(arg);
 
-    if (TYPE(arg) == T_ARRAY) {
-	argv = ALLOCA_N(VALUE, RARRAY(arg)->len + 1);
-	argv[0] = str;
-	MEMCPY(argv+1, RARRAY(arg)->ptr, VALUE, RARRAY(arg)->len);
-	return rb_f_sprintf(RARRAY(arg)->len+1, argv);
+    if (!NIL_P(tmp)) {
+	return rb_str_format(RARRAY_LEN(tmp), RARRAY_PTR(tmp), str);
     }
 
-    argv = ALLOCA_N(VALUE, 2);
-    argv[0] = str;
-    argv[1] = arg;
-    return rb_f_sprintf(2, argv);
+    return rb_str_format(1, &arg, str);
 }
 
 static int
@@ -694,18 +688,14 @@
     return str;
 }
 
-VALUE
-rb_str_buf_cat(str, ptr, len)
+static VALUE
+str_buf_cat(str, ptr, len)
     VALUE str;
     const char *ptr;
     long len;
 {
     long capa, total;
 
-    if (len == 0) return str;
-    if (len < 0) {
-	rb_raise(rb_eArgError, "negative string size (or size too big)");
-    }
     rb_str_modify(str);
     if (FL_TEST(str, STR_ASSOC)) {
 	FL_UNSET(str, STR_ASSOC);
@@ -714,9 +704,16 @@
     else {
 	capa = RSTRING(str)->aux.capa;
     }
+    if (RSTRING(str)->len >= LONG_MAX - len) {
+	rb_raise(rb_eArgError, "string sizes too big");
+    }
     total = RSTRING(str)->len+len;
     if (capa <= total) {
 	while (total > capa) {
+	    if (capa + 1 >= LONG_MAX / 2) {
+		capa = total;
+		break;
+	    }
 	    capa = (capa + 1) * 2;
 	}
 	RESIZE_CAPA(str, capa);
@@ -729,6 +726,19 @@
 }
 
 VALUE
+rb_str_buf_cat(str, ptr, len)
+    VALUE str;
+    const char *ptr;
+    long len;
+{
+    if (len == 0) return str;
+    if (len < 0) {
+	rb_raise(rb_eArgError, "negative string size (or size too big)");
+    }
+    return str_buf_cat(str, ptr, len);
+}
+
+VALUE
 rb_str_buf_cat2(str, ptr)
     VALUE str;
     const char *ptr;
@@ -747,7 +757,7 @@
     }
     if (FL_TEST(str, STR_ASSOC)) {
 	rb_str_modify(str);
-	REALLOC_N(RSTRING(str)->ptr, char, RSTRING(str)->len+len);
+	REALLOC_N(RSTRING(str)->ptr, char, RSTRING(str)->len+len+1);
 	memcpy(RSTRING(str)->ptr + RSTRING(str)->len, ptr, len);
 	RSTRING(str)->len += len;
 	RSTRING(str)->ptr[RSTRING(str)->len] = '\0'; /* sentinel */
@@ -769,29 +779,8 @@
 rb_str_buf_append(str, str2)
     VALUE str, str2;
 {
-    long capa, len;
-
-    rb_str_modify(str);
-    if (FL_TEST(str, STR_ASSOC)) {
-	FL_UNSET(str, STR_ASSOC);
-	capa = RSTRING(str)->aux.capa = RSTRING(str)->len;
-    }
-    else {
-	capa = RSTRING(str)->aux.capa;
-    }
-    len = RSTRING(str)->len+RSTRING(str2)->len;
-    if (capa <= len) {
-	while (len > capa) {
-	    capa = (capa + 1) * 2;
-	}
-	RESIZE_CAPA(str, capa);
-    }
-    memcpy(RSTRING(str)->ptr + RSTRING(str)->len,
-	   RSTRING(str2)->ptr, RSTRING(str2)->len);
-    RSTRING(str)->len += RSTRING(str2)->len;
-    RSTRING(str)->ptr[RSTRING(str)->len] = '\0'; /* sentinel */
+    str_buf_cat(str, RSTRING(str2)->ptr, RSTRING(str2)->len);
     OBJ_INFECT(str, str2);
-
     return str;
 }
 
@@ -4657,7 +4646,7 @@
     rb_define_method(rb_cString, "casecmp", rb_str_casecmp, 1);
     rb_define_method(rb_cString, "+", rb_str_plus, 1);
     rb_define_method(rb_cString, "*", rb_str_times, 1);
-    rb_define_method(rb_cString, "%", rb_str_format, 1);
+    rb_define_method(rb_cString, "%", rb_str_format_m, 1);
     rb_define_method(rb_cString, "[]", rb_str_aref_m, -1);
     rb_define_method(rb_cString, "[]=", rb_str_aset_m, -1);
     rb_define_method(rb_cString, "insert", rb_str_insert, 2);
