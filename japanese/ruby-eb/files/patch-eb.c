--- eb.c.orig	2004-07-12 17:46:01.000000000 +0000
+++ eb.c	2013-06-01 16:49:10.715644813 +0000
@@ -19,6 +19,13 @@
 
 #if HAVE_EB_SYSDEFS_H
 #include <eb/sysdefs.h>
+#if (defined RUBY_EB_ENABLE_PTHREAD && !defined(EB_ENABLE_PTHREAD)) \
+ || (!defined RUBY_EB_ENABLE_PTHREAD && defined(EB_ENABLE_PTHREAD))
+#error The EB library is incompatible with EB heders.
+#endif
+
+#elif defined RUBY_EB_ENABLE_PTHREAD
+#define EBCONF_ENABLE_PTHREAD 1
 #endif
 
 #include <eb/eb.h>
@@ -55,6 +62,21 @@
 
 #define APPENDIX_EB_IVAR "__appendix"
 
+#ifdef HAVE_TYPE_RB_ENCODING
+#include <ruby/encoding.h>
+#define REB_TO_RB_ENCODING(reb) rb_enc_from_index(NUM2INT(rb_ivar_get(reb, id_eb_encidx)))
+#else
+#define rb_encoding void
+#define REB_TO_RB_ENCODING(reb) NULL
+#define rb_ascii8bit_encindex() 0
+#define rb_enc_find_index(name) 0
+#define rb_usascii_str_new_cstr(ptr) rb_str_new2(ptr)
+#define rb_filesystem_str_new_cstr(ptr) rb_str_new2(ptr)
+/* "((void)enc, ...)" is a hack to suppress warnings: unused variable 'enc' */
+#define rb_external_str_new_with_enc(ptr, len, enc) ((void)enc, rb_tainted_str_new((ptr), (len)))
+#define rb_str_export_to_enc(str, enc) ((void)enc, (str))
+#endif
+
 struct ExtFont {
     int code;
     int wideflag;               /* boolean */
@@ -67,20 +89,30 @@
 
 
 
-VALUE mEB;
-VALUE cEBook;
-VALUE cEBCancel;
-VALUE cEBPosition;
-VALUE cEBExtFont;
-VALUE cEBHook;
-VALUE cEBAppendix;
+static VALUE mEB;
+static VALUE cEBook;
+static VALUE cEBCancel;
+static VALUE cEBPosition;
+static VALUE cEBExtFont;
+static VALUE cEBHook;
+static VALUE cEBAppendix;
 
-ID id_call;
+static ID id_call;
+static ID id_eb_encidx;
+
+static void
+reb_check_type(VALUE obj, VALUE klass)
+{
+    if (!rb_obj_is_kind_of(obj, klass)) {
+        rb_raise(rb_eTypeError, "wrong argument type %s (expected %s)",
+                 rb_obj_classname(obj), rb_class2name(klass));
+    }
+}
 
-int
+static int
 text_hook(EB_Book * book, EB_Appendix * appendix, void *container, EB_Hook_Code code, int argc, const int *argv)
 {
-    VALUE func, ret_buff, rb_argv, rb_eb, rb_hookset;
+    VALUE func, ret_buff, rargv, rb_eb, rb_hookset;
     int idx;
     char *tmpbuffer;
 
@@ -92,17 +124,17 @@
 
     func = rb_ary_entry(rb_iv_get(rb_hookset, HOOKSET_PROCS_IVAR), code);
 
-    rb_argv = rb_ary_new2(argc);
+    rargv = rb_ary_new2(argc);
     for (idx = 0; idx < argc; idx++) {
-        rb_ary_store(rb_argv, idx, INT2FIX(argv[idx]));
+        rb_ary_store(rargv, idx, INT2FIX(argv[idx]));
     }
 
-    ret_buff = rb_funcall(func, id_call, 2, rb_eb, rb_argv);
+    ret_buff = rb_funcall(func, id_call, 2, rb_eb, rargv);
     if (ret_buff != Qnil) {
         if (TYPE(ret_buff) == T_STRING) {
             ret_buff = rb_funcall(ret_buff, rb_intern("to_str"), 0);
         }
-        tmpbuffer = STR2CSTR(ret_buff);
+        tmpbuffer = StringValueCStr(ret_buff);
         eb_write_text_string(book, tmpbuffer);
     }
     return 0;
@@ -164,6 +196,7 @@
     reb_appendix = Data_Make_Struct(cEBAppendix, EB_Appendix, 0, finalize_appendix, appendix);
     eb_initialize_appendix(appendix);
     rb_iv_set(robj, APPENDIX_EB_IVAR, reb_appendix);
+    rb_ivar_set(robj, id_eb_encidx, INT2FIX(rb_ascii8bit_encindex()));
 
     return robj;
 }
@@ -185,13 +218,30 @@
 {
     EB_Book *eb;
     int r;
+    EB_Character_Code charcode = EB_CHARCODE_INVALID;
+    int encidx;
 
     Data_Get_Struct(obj, EB_Book, eb);
-    r = eb_bind(eb, STR2CSTR(path));
+    r = eb_bind(eb, StringValueCStr(path));
     if (r != EB_SUCCESS) {
-        rb_raise(rb_eRuntimeError, eb_error_message(r));
+        rb_raise(rb_eRuntimeError, "%s", eb_error_message(r));
         return Qfalse;
     }
+
+    eb_character_code(eb, &charcode);
+    switch (charcode) {
+    case EB_CHARCODE_ISO8859_1:
+        encidx = rb_enc_find_index("ISO-8859-1");
+        break;
+    case EB_CHARCODE_JISX0208:
+        encidx = rb_enc_find_index("EUC-JP");
+        break;
+    default:
+        encidx = rb_ascii8bit_encindex();
+        break;
+    }
+    rb_ivar_set(obj, id_eb_encidx, INT2FIX(encidx));
+
     return obj;
 }
 
@@ -206,13 +256,13 @@
     eb_error = eb_disc_type(eb, &r);
     switch (r) {
     case EB_DISC_EB:
-        return rb_str_new2("EB/EBG/EBXA/EBXA-C/S-EBXA");
+        return rb_usascii_str_new_cstr("EB/EBG/EBXA/EBXA-C/S-EBXA");
         break;
     case EB_DISC_EPWING:
-        return rb_str_new2("EPWING");
+        return rb_usascii_str_new_cstr("EPWING");
         break;
     }
-    return rb_str_new2("Unknown");
+    return rb_usascii_str_new_cstr("Unknown");
 }
 
 static VALUE
@@ -241,29 +291,29 @@
 reb_path(VALUE obj)
 {
     EB_Book *eb;
-    char r[1024];               /*絶対値はまずいと思う */
+    char r[EB_MAX_PATH_LENGTH + 1];
 
     Data_Get_Struct(obj, EB_Book, eb);
     eb_error = eb_path(eb, r);
 
-    return rb_str_new2(r);
+    return rb_filesystem_str_new_cstr(r);
 }
 
 static VALUE
 reb_charcode(VALUE obj)
 {
     EB_Book *eb;
-    EB_Character_Code r;
+    EB_Character_Code r = EB_CHARCODE_INVALID;
 
     Data_Get_Struct(obj, EB_Book, eb);
     eb_error = eb_character_code(eb, &r);
 
     switch (r) {
     case EB_CHARCODE_ISO8859_1:
-        return rb_str_new2("ISO8859_1");
+        return rb_usascii_str_new_cstr("ISO8859_1");
         break;
     case EB_CHARCODE_JISX0208:
-        return rb_str_new2("JISX0208");
+        return rb_usascii_str_new_cstr("JISX0208");
         break;
     }
     return Qnil;
@@ -303,19 +353,21 @@
 reb_subbooktitle(int argc, VALUE * argv, VALUE obj)
 {
     EB_Book *eb;
-    char r[1024];               /*絶対値はまずいと思う */
+    char r[EB_MAX_TITLE_LENGTH + 1];
+    rb_encoding *enc = REB_TO_RB_ENCODING(obj);
 
     Data_Get_Struct(obj, EB_Book, eb);
     eb_error = (argc == 0) ?
         eb_subbook_title(eb, r) : eb_subbook_title2(eb, NUM2INT(argv[0]), r);
-    return rb_str_new2(r);
+
+    return rb_external_str_new_with_enc(r, strlen(r), enc);
 }
 
 static VALUE
 reb_subbookdirectory(int argc, VALUE * argv, VALUE obj)
 {
     EB_Book *eb;
-    char r[1024];               /*絶対値はまずいと思う */
+    char r[EB_MAX_DIRECTORY_NAME_LENGTH + 1];
 
     Data_Get_Struct(obj, EB_Book, eb);
     eb_error = (argc == 0) ?
@@ -371,7 +423,7 @@
     return obj;
 }
 
-VALUE
+static VALUE
 have_search(VALUE obj, EB_Error_Code(*funct) (EB_Book *))
 {
     EB_Book *eb;
@@ -379,7 +431,7 @@
     Data_Get_Struct(obj, EB_Book, eb);
     r = (*funct) (eb);
     if (!r && eb_error == EB_ERR_NO_CUR_SUB) {
-        rb_raise(rb_eRuntimeError, eb_error_message(eb_error));
+        rb_raise(rb_eRuntimeError, "%s", eb_error_message(eb_error));
         return Qfalse;
     }
     return (r) ? Qtrue : Qfalse;
@@ -432,8 +484,9 @@
 static VALUE
 content_read(VALUE reb, EB_Book * eb, EB_Appendix * appendix, EB_Hookset * text_hookset)
 {
-    int len;
+    ssize_t len;
     char desc[MAX_STRLEN + 1];
+    rb_encoding *enc = REB_TO_RB_ENCODING(reb);
 
     eb_error = eb_read_text(eb, appendix, text_hookset, (void *) reb,
                             MAX_STRLEN, desc, &len);
@@ -442,7 +495,7 @@
         rb_raise(rb_eRuntimeError, "fail fetching text");
         return Qfalse;
     }
-    return rb_str_new(desc, len);
+    return rb_external_str_new_with_enc(desc, len, enc);
 }
 
 static VALUE
@@ -455,14 +508,15 @@
     return content_read(reb, eb, appendix, text_hookset);
 }
 
-VALUE
+static VALUE
 get_item(VALUE reb, EB_Book * eb, EB_Hit * hit)
 {
     EB_Hookset *text_hookset;
     EB_Appendix *appendix;
     VALUE item;
     char desc[MAX_STRLEN + 1];
-    int len;
+    ssize_t len;
+    rb_encoding *enc = REB_TO_RB_ENCODING(reb);
     item = rb_ary_new2(2);
 
     if (eb_seek_text(eb, &(hit->heading)) < 0) {
@@ -480,14 +534,14 @@
         return Qfalse;
     }
 
-    rb_ary_push(item, rb_str_new(desc, len));
+    rb_ary_push(item, rb_external_str_new_with_enc(desc, len, enc));
     rb_ary_push(item, content_fetch_from_pos(reb, eb, &(hit->text), appendix, text_hookset));
 
     return item;
 }
 
 
-VALUE
+static VALUE
 hitmaker(VALUE reb, EB_Book * eb, unsigned int max, int flag)
 {
     int hitpushed, hitcount;
@@ -536,20 +590,22 @@
     return (flag == 0) ? robj : INT2NUM(hitpushed);
 }
 
-void
-set_keywords(VALUE array, char **buffer)
+static void
+set_keywords(VALUE array, char **buffer, volatile VALUE *gc_guard, rb_encoding *enc)
 {
     int i, sz;
+
     if (TYPE(array) != T_ARRAY) {
         rb_raise(rb_eTypeError, "wordlist must be array of String.");
     }
 
-    sz = RARRAY(array)->len;
+    sz = RARRAY_LEN(array);
     if (sz > MAX_KEYWORDS) {
         rb_raise(rb_eRuntimeError, "too many keywords(%d).", sz);
     }
     for (i = 0; i < sz; i++) {
-        buffer[i] = STR2CSTR(rb_ary_entry(array, i));
+        gc_guard[i] = rb_str_export_to_enc(rb_ary_entry(array, i), enc);
+        buffer[i] = RSTRING_PTR(gc_guard[i]);
     }
     buffer[sz] = NULL;
 }
@@ -563,6 +619,12 @@
     char *buffer[MAX_KEYWORDS + 1];
     int max;
     int r;
+    rb_encoding *enc = REB_TO_RB_ENCODING(obj);
+    /* The following two variables are used to prevent GC from freeing
+     * temporary objects.
+     */
+    volatile VALUE gc_guard[MAX_KEYWORDS];
+    volatile VALUE str;
 
     if (argc < 1) {
         rb_raise(rb_eArgError, "missing searchstring");
@@ -570,10 +632,11 @@
     }
 
     if (wordtype == SEARCHTYPE_WORD) {
-        word = STR2CSTR(argv[0]);
+        str = rb_str_export_to_enc(argv[0], enc);
+        word = RSTRING_PTR(str);
     }
     else {
-        set_keywords(argv[0], buffer);
+        set_keywords(argv[0], buffer, gc_guard, enc);
         word = buffer;
     }
     max = (argc > 1) ? NUM2INT(argv[1]) : -1;
@@ -616,10 +679,11 @@
 
 
 /*   Thanks for Kuroda-san  */
-VALUE
+static VALUE
 hitmaker2(VALUE reb, EB_Book * eb, unsigned int max, int flag)
 {
-    int hitcount, i, len, broken;
+    int hitcount, i, broken;
+    ssize_t len;
     int hitpushed;
     VALUE robj, item, can;
     EB_Hit hits[MAX_HITS];
@@ -629,6 +693,7 @@
     char descbuf2[MAX_STRLEN + 1];
     char *prevdesc;
     int prevpage, prevoffset;
+    rb_encoding *enc = REB_TO_RB_ENCODING(reb);
     desc = descbuf1;
 
 /*** this 2 lines necessary? (2/4) eblook do like this ***/
@@ -669,7 +734,7 @@
 
             item = rb_ary_new2(2);
             rb_ary_push(item, Data_Make_Struct(cEBPosition, EB_Position, 0, free, ebpos));
-            rb_ary_push(item, rb_str_new(desc, len));
+            rb_ary_push(item, rb_external_str_new_with_enc(desc, len, enc));
             ebpos->page = hits[i].text.page;
             ebpos->offset = hits[i].text.offset;
 
@@ -707,7 +772,7 @@
     return (flag == 0) ? robj : INT2NUM(hitpushed);
 }
 
-VALUE
+static VALUE
 position_search(int argc, VALUE * argv, VALUE obj, int wordtype,
                 EB_Error_Code(*funct) ())
 {
@@ -716,6 +781,12 @@
     void *word;
     int max;
     int r;
+    rb_encoding *enc = REB_TO_RB_ENCODING(obj);
+    /* The following two variables are used to prevent GC from freeing
+     * temporary objects.
+     */
+    volatile VALUE gc_guard[MAX_KEYWORDS];
+    volatile VALUE str;
 
     if (argc < 1) {
         rb_raise(rb_eArgError, "missing searchstring");
@@ -723,10 +794,11 @@
     }
 
     if (wordtype == SEARCHTYPE_WORD) {
-        word = STR2CSTR(argv[0]);
+        str = rb_str_export_to_enc(argv[0], enc);
+        word = RSTRING_PTR(str);
     }
     else {
-        set_keywords(argv[0], buffer);
+        set_keywords(argv[0], buffer, gc_guard, enc);
         word = buffer;
     }
     max = (argc > 1) ? NUM2INT(argv[1]) : -1;
@@ -775,6 +847,7 @@
     VALUE robj;
 
     Data_Get_Struct(obj, EB_Book, eb);
+    reb_check_type(position, cEBPosition);
     Data_Get_Struct(position, EB_Position, ppos);
     apx = get_eb_appendix(obj);
     thook = get_eb_texthook(obj);
@@ -785,7 +858,7 @@
         do {
             rb_yield(robj);
             robj = content_read(obj, eb, apx, thook);
-            dlen = MAX_STRLEN - RSTRING(robj)->len;
+            dlen = MAX_STRLEN - RSTRING_LEN(robj);
         } while (dlen == 0);
     }
     return robj;
@@ -803,7 +876,7 @@
 static VALUE
 reb_sethookset(VALUE obj, VALUE hkset)
 {
-    if (rb_funcall(hkset, rb_intern("is_a?"), 1, cEBHook) != Qtrue && hkset != Qnil) {
+    if (!rb_obj_is_kind_of(hkset, cEBHook) && !NIL_P(hkset)) {
         rb_raise(rb_eArgError, "hookset must be nil or an instance of Hookset");
         return Qfalse;
     }
@@ -874,7 +947,7 @@
     return robj;
 }
 
-EB_Font_Code
+static EB_Font_Code
 get_fontcode(EB_Book * eb)
 {
     EB_Font_Code r;
@@ -991,7 +1064,7 @@
 {
     char buffer[MAX_STRLEN];
     long readbytes;
-    int bitmap_len;
+    ssize_t bitmap_len;
     int blocksize;
     EB_Error_Code retcode;
     VALUE robj;
@@ -1010,7 +1083,7 @@
     while (bitmap_len != 0) {
         retcode = eb_read_binary(eb, blocksize, buffer, &bitmap_len);
         if (retcode != EB_SUCCESS) {
-            rb_raise(rb_eRuntimeError, eb_error_message(retcode));
+            rb_raise(rb_eRuntimeError, "%s", eb_error_message(retcode));
             return Qfalse;
         }
         if (iterateflag) {
@@ -1024,6 +1097,7 @@
                 break;
         }
     }
+    rb_obj_taint(robj);
 
     return iterateflag ? INT2NUM(readbytes) : robj;
 }
@@ -1036,6 +1110,7 @@
     EB_Position *epos;
 
     Data_Get_Struct(obj, EB_Book, eb);
+    reb_check_type(pos, cEBPosition);
     Data_Get_Struct(pos, EB_Position, epos);
 
     retcode = eb_set_binary_mono_graphic(eb, epos, NUM2UINT(width), NUM2UINT(height));
@@ -1086,7 +1161,9 @@
     maxlen = (argc > 2) ? NUM2UINT(argv[2]) : MAX_STRLEN;
 
     Data_Get_Struct(obj, EB_Book, eb);
+    reb_check_type(argv[0], cEBPosition);
     Data_Get_Struct(argv[0], EB_Position, spos);
+    reb_check_type(argv[1], cEBPosition);
     Data_Get_Struct(argv[1], EB_Position, epos);
 
     retcode = eb_set_binary_wave(eb, spos, epos);
@@ -1104,7 +1181,7 @@
     EB_Error_Code retcode;
     EB_Book *eb;
     long maxlen;
-    int param[4];
+    unsigned int param[4];
     int i;
 
     if (argc < 4) {
@@ -1129,8 +1206,8 @@
 reb_compose_mpegfilename(int argc, VALUE * argv, VALUE obj)
 {
     EB_Error_Code retcode;
-    char buffer[1024];
-    int param[4];
+    char buffer[EB_MAX_DIRECTORY_NAME_LENGTH + 1];
+    unsigned int param[4];
     int i;
     if (argc != 4) {
         rb_raise(rb_eArgError, "4 args needed.(code1-code4)");
@@ -1174,7 +1251,7 @@
         return Qnil;
     }
     else if (err != EB_SUCCESS) {
-        rb_raise(rb_eRuntimeError, eb_error_message(err));
+        rb_raise(rb_eRuntimeError, "%s", eb_error_message(err));
         return Qfalse;
     }
     return content_fetch_from_pos(obj, eb, &pos,
@@ -1212,7 +1289,7 @@
     EB_Appendix *appendix;
     appendix = get_eb_appendix(obj);
     if (path != Qnil) {
-        eb_bind_appendix(appendix, STR2CSTR(path));
+        eb_bind_appendix(appendix, StringValueCStr(path));
     }
     else {
         eb_finalize_appendix(appendix);
@@ -1291,7 +1368,7 @@
     };
 
     (*conv_func) (font->bitmap, width, height, buffer, &size);
-    robj = rb_str_new(buffer, size);
+    robj = rb_tainted_str_new(buffer, size);
     free(buffer);
     return robj;
 }
@@ -1439,13 +1516,17 @@
         break;
     case 2:
         proc = argv[1];
+        if (!rb_respond_to(proc, id_call)) {
+            rb_raise(rb_eArgError, "wrong type argument %s (should respond to 'call')",
+                     rb_obj_classname(proc));
+        }
         break;
     default:
         rb_raise(rb_eArgError, "wrong # of arguments");
         break;
     }
 
-    hook_type = FIX2UINT(argv[0]);
+    hook_type = NUM2UINT(argv[0]);
     rb_ary_store(rb_iv_get(self, HOOKSET_PROCS_IVAR), hook_type, proc);
     Data_Get_Struct(self, EB_Hookset, text_hookset);
     hook.code = hook_type;
@@ -1485,7 +1566,7 @@
     return Qfalse;
 }
 
-void
+static void
 define_constants_under(VALUE mod)
 {
     rb_define_const(mod, "HOOK_INITIALIZE", INT2FIX(EB_HOOK_INITIALIZE));
@@ -1557,7 +1638,19 @@
 void
 Init_eb()
 {
+#ifdef HAVE_EB_PTHREAD_ENABLED
+#ifdef RUBY_EB_ENABLE_PTHREAD
+    if (!eb_pthread_enabled()) {
+       rb_raise(rb_eRuntimeError, "The RubyEB is compiled for pthread-enabled EB library.");
+     }
+#else
+    if (eb_pthread_enabled()) {
+       rb_raise(rb_eRuntimeError, "The RubyEB is compiled for pthread-disabled EB library.");
+     }
+#endif
+#endif
     id_call = rb_intern("call");
+    id_eb_encidx = rb_intern("@__ruby_eb_encidx__");
 
     mEB = rb_define_module("EB");
     rb_define_const(mEB,"RUBYEB_VERSION",rb_str_new2(RUBYEB_VERSION));
