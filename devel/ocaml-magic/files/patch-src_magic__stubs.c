--- src/magic_stubs.c.orig	2008-03-23 20:39:45 UTC
+++ src/magic_stubs.c
@@ -53,7 +53,7 @@ static void raise_magic_failure(const char * msg)
 {
   static value * exn = NULL;
   if (exn == NULL) exn = caml_named_value("Magic.Failure");
-  raise_with_string(*exn, (char *) msg);
+  caml_raise_with_string(*exn, (char *) msg);
 }
 
 /* [raise_on_error] raises an exception according to the error that
@@ -73,20 +73,20 @@ static void raise_on_error(const char* fname, const ma
   if (err_magic != NULL) {
     /* libmagic error */
     if ((errmsg = malloc(flen + strlen(err_magic) + 1)) == NULL)
-      raise_out_of_memory();
+      caml_raise_out_of_memory();
     if (exn == NULL) exn = caml_named_value("Magic.Failure");
     strcpy(errmsg, fname);
     strcpy(errmsg + flen, err_magic);
-    verrmsg = copy_string(errmsg);
+    verrmsg = caml_copy_string(errmsg);
     free(errmsg); /* err_magic is freed by magic_close */
-    raise_with_arg(*exn, verrmsg);
+    caml_raise_with_arg(*exn, verrmsg);
   }
   else  {
     /* System error */
     const int err = magic_errno(cookie);
     int len = 80;  /* buffer length */
 
-    if ((errmsg = malloc(len)) == NULL) raise_out_of_memory();
+    if ((errmsg = malloc(len)) == NULL) caml_raise_out_of_memory();
     strcpy(errmsg, fname);
 #ifdef HAVE_STRERROR_R
     /* Allocate buffer [errmsg] until there is enough space for the
@@ -95,15 +95,15 @@ static void raise_on_error(const char* fname, const ma
       /* Reallocate to a bigger size -- no need to keep the contents */
       len *= 2;
       free(errmsg);
-      if ((errmsg = malloc(len)) == NULL) raise_out_of_memory();
+      if ((errmsg = malloc(len)) == NULL) caml_raise_out_of_memory();
       strcpy(errmsg, fname);
     }
 #else
     strncat(errmsg, strerror(err), len - flen - 1);
 #endif
-    verrmsg = copy_string(errmsg);
+    verrmsg = caml_copy_string(errmsg);
     free(errmsg);
-    raise_sys_error(verrmsg);
+    caml_raise_sys_error(verrmsg);
   }
 
   CAMLreturn0;
@@ -147,7 +147,7 @@ static struct custom_operations cookie_ops = {
     /* deserialize */ custom_deserialize_default
 };
 
-#define ALLOC_COOKIE alloc_custom(&cookie_ops, sizeof(magic_t), \
+#define ALLOC_COOKIE caml_alloc_custom(&cookie_ops, sizeof(magic_t), \
                      sizeof(magic_t), 40 * sizeof(magic_t))
 
 /*
@@ -169,22 +169,22 @@ CAMLprim value ocaml_magic_open(value flags)
     else {
       const int err = errno; /* save it */
 
-      if ((errmsg = malloc(len)) == NULL) raise_out_of_memory();
+      if ((errmsg = malloc(len)) == NULL) caml_raise_out_of_memory();
       strcpy(errmsg, "Magic.create: "); /* 14 chars */
 #ifdef HAVE_STRERROR_R
       /* No cookie yet, so one cannot use the above generic err fun */
       while(strerror_r(err, errmsg + 14, len - 14) < 0) {
         len *= 2;
         free(errmsg);
-        if ((errmsg = malloc(len)) == NULL) raise_out_of_memory();
+        if ((errmsg = malloc(len)) == NULL) caml_raise_out_of_memory();
         strcpy(errmsg, "Magic.create: ");
       }
 #else
       strncat(errmsg, strerror(err), len - 15);
 #endif
-      verrmsg = copy_string(errmsg);
+      verrmsg = caml_copy_string(errmsg);
       free(errmsg);
-      raise_sys_error(verrmsg);
+      caml_raise_sys_error(verrmsg);
     }
   }
   CAMLreturn(c);
@@ -207,11 +207,11 @@ CAMLprim value ocaml_magic_file(value c, value fname)
   const char * ans;
   const magic_t cookie = COOKIE_VAL(c);
 
-  if (cookie == NULL) invalid_argument("Magic.file");
+  if (cookie == NULL) caml_invalid_argument("Magic.file");
   if ((ans = magic_file(cookie, String_val(fname))) == NULL) {
     raise_on_error("Magic.file: ", cookie);
   }
-  CAMLreturn(copy_string(ans));
+  CAMLreturn(caml_copy_string(ans));
 }
 
 CAMLprim value ocaml_magic_buffer(value c, value buf, value len)
@@ -224,7 +224,7 @@ CAMLprim value ocaml_magic_buffer(value c, value buf, 
   if ((ans = magic_buffer(cookie, String_val(buf), Int_val(len)))
       == NULL)
     raise_on_error("Magic.buffer: ", cookie);
-  CAMLreturn(copy_string(ans));
+  CAMLreturn(caml_copy_string(ans));
 }
 
 
