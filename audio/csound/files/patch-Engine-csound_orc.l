--- Engine/csound_orc.l.orig	2011-12-22 19:41:53.000000000 +0900
+++ Engine/csound_orc.l	2011-12-27 21:28:55.000000000 +0900
@@ -288,7 +288,7 @@
                   /* printf("Push %p macro stack; new body #%s#\n",
                             PARM->macros, mm->body); */
                   /* printf("Push buffer %p -> ", YY_CURRENT_BUFFER); */
-                  yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
+                  //yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
                   yy_scan_string(mm->body, yyscanner);
                   /* printf("%p\n", YY_CURRENT_BUFFER); */
                  }
@@ -313,7 +313,7 @@
                   PARM->alt_stack[PARM->macro_stack_ptr].n = 0;
                   PARM->alt_stack[PARM->macro_stack_ptr++].s = NULL;
                   /* printf("Push buffer %p -> ", YY_CURRENBUFFER_TOKEN); */
-                  yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
+                  //yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
                   yy_scan_string(mm->body, yyscanner);
                   /* printf("%p\n", YY_CURRENT_BUFFER); */
                 }
@@ -367,7 +367,7 @@
                   PARM->alt_stack[PARM->macro_stack_ptr].n = mm->acnt;
                   PARM->alt_stack[PARM->macro_stack_ptr++].s = PARM->macros;
                   /* printf("Push %p macro stack\n",PARM->macros); */
-                  yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
+                  //yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
                   yy_scan_string(mm->body, yyscanner);
                 }
 {MACRONAMEDA}    {
@@ -419,7 +419,7 @@
                   /* printf("New body: ...#%s#\n", mm->body); */
                   PARM->alt_stack[PARM->macro_stack_ptr].n = mm->acnt;
                   PARM->alt_stack[PARM->macro_stack_ptr++].s = PARM->macros;
-                  yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
+                  //yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
                   yy_scan_string(mm->body, yyscanner);
                 }
 {INTGR}         {
@@ -448,7 +448,7 @@
                   MACRO *x, *y;
                   int n;
                   printf("Leaving buffer %p\n", YY_CURRENT_BUFFER);
-                  yypop_buffer_state(yyscanner);
+                  //yypop_buffer_state(yyscanner);
                   if ( !YY_CURRENT_BUFFER ) yyterminate();
                   printf("End of input; popping to %p\n", YY_CURRENT_BUFFER);
                   if (PARM->clearBufferAfterEOF)
@@ -581,7 +581,7 @@
     PARM->alt_stack[PARM->macro_stack_ptr].n = 0;
     PARM->alt_stack[PARM->macro_stack_ptr++].s = NULL;
     PARM->isInclude = PARM->clearBufferAfterEOF = 1;
-    yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
+    //yypush_buffer_state(YY_CURRENT_BUFFER, yyscanner);
     yy_scan_string(cf->body, yyscanner);
 }
 
