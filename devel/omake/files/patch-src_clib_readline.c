$NetBSD: patch-af,v 1.1 2010/12/17 09:40:14 wiz Exp $

From upstream SVN.

--- src/clib/readline.c.orig	2007-05-15 19:03:03.000000000 +0000
+++ src/clib/readline.c
@@ -134,7 +134,7 @@ static char **readline_completion(char *
         CAMLreturnT(char **, 0);
 
     /* The callback returns an array of strings */
-    request = copy_string(text);
+    request = caml_copy_string(text);
     response = caml_callback(*callbackp, request);
     
     /* Copy the array of strings */
@@ -726,9 +726,9 @@ static ProcessCode processor(ReadLine *r
 
     /* Input loop */
     while(1) {
-        enter_blocking_section();
+        caml_enter_blocking_section();
         status = ReadConsoleInput(readp->console_in, input, INPUT_COUNT, &count);
-        leave_blocking_section();
+        caml_leave_blocking_section();
         if(status == 0) {
             print_error("ReadConsoleInput");
             return CODE_EOF;
@@ -766,11 +766,11 @@ static void readline_cooked(ReadLine *re
 {
     char *s;
 
-    enter_blocking_section();
+    caml_enter_blocking_section();
     s = fgets(readp->current.buffer, LINE_MAX, stdin);
-    leave_blocking_section();
+    caml_leave_blocking_section();
     if(s == 0)
-        raise_end_of_file();
+        caml_raise_end_of_file();
     readp->current.length = strlen(readp->current.buffer);
 }
 
@@ -1053,7 +1053,7 @@ value omake_readline(value v_prompt)
 
     /* Copy it to a string */
     linep = &readp->current;
-    v_str = alloc_string(linep->length);
+    v_str = caml_alloc_string(linep->length);
     memcpy(String_val(v_str), linep->buffer, linep->length);
 
     /* Reset the current buffer */
@@ -1105,7 +1105,7 @@ value omake_readline_init(value v_unit)
     c_stdin = GetStdHandle(STD_INPUT_HANDLE);
     c_stdout = GetStdHandle(STD_OUTPUT_HANDLE);
     if(c_stdin == INVALID_HANDLE_VALUE || c_stdout == INVALID_HANDLE_VALUE)
-        failwith("omake_readline_init: no standard channels");
+        caml_failwith("omake_readline_init: no standard channels");
 
     /* Check if it is a console */
     is_console = 1;
@@ -1179,18 +1179,18 @@ static ReadLine *AllocReadLine(int is_co
     /* Allocate */
     readp = (ReadLine *) malloc(sizeof(ReadLine));
     if(readp == NULL)
-        failwith("AllocReadLine: out of memory");
+        caml_failwith("AllocReadLine: out of memory");
     memset(readp, 0, sizeof(ReadLine));
 
     /* Initialize */
     readp->buffer = malloc(LINE_MAX);
     if (readp->buffer == NULL)
-        failwith("AllocReadLine: out of memory");
+        caml_failwith("AllocReadLine: out of memory");
     readp->buffer_size = LINE_MAX;
 
     readp->prompt = malloc(MAX_PROMPT_LENGTH);
     if (readp->prompt == NULL)
-        failwith("AllocReadLine: out of memory");
+        caml_failwith("AllocReadLine: out of memory");
     readp->prompt_size = MAX_PROMPT_LENGTH;
 
     readp->console_in = console_in;
@@ -1262,7 +1262,7 @@ static void readline_raw(ReadLine *readp
         if(length >= readp->buffer_size) {
             char *new_buffer = malloc(length + 1);
             if(new_buffer == NULL)
-                failwith("readline_raw: out of memory");
+                caml_failwith("readline_raw: out of memory");
             free(readp->buffer);
             readp->buffer = new_buffer;
             readp->buffer_size = length + 1;
@@ -1307,7 +1307,7 @@ static void do_readline(ReadLine *readp,
             readp->prompt = malloc(new_size);
             if (readp->prompt == NULL) {
                 readp->prompt = old_prompt;
-                failwith("do_readline: out of memory");
+                caml_failwith("do_readline: out of memory");
             } else {
                 memcpy(readp->prompt, old_prompt, i);
                 free(old_prompt);
@@ -1545,7 +1545,7 @@ value omake_readline(value v_prompt)
     do_readline(readp, String_val(v_prompt));
 
     /* Copy it to the buffer */
-    v_str = alloc_string(readp->length);
+    v_str = caml_alloc_string(readp->length);
     memcpy(String_val(v_str), readp->buffer, readp->length);
 
     /* Reset the current buffer */
@@ -1609,7 +1609,7 @@ value omake_rl_prompt_wrappers(value v_u
         CAMLlocal2(s1, s2);
         s1 = caml_copy_string(begin);
         s2 = caml_copy_string(end);
-        buf = alloc_tuple(2);
+        buf = caml_alloc_tuple(2);
         Field(buf, 0) = s1;
         Field(buf, 1) = s2;
     }
@@ -1617,7 +1617,7 @@ value omake_rl_prompt_wrappers(value v_u
     {
         CAMLlocal1(emptystr);
         emptystr = caml_copy_string("");
-        buf = alloc_tuple(2);
+        buf = caml_alloc_tuple(2);
         Field(buf, 0) = emptystr;
         Field(buf, 1) = emptystr;
     }
