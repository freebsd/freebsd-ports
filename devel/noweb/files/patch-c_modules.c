--- c/modules.c.orig	Wed Mar 28 14:49:00 2001
+++ c/modules.c	Thu Nov 13 20:15:53 2003
@@ -17,7 +17,7 @@
 
 static
 void append(Module mp, struct modpart *p);
-#line 227 "modules.nw"
+#line 233 "modules.nw"
 static int seekcycle(Module mp, Parent parent);
 #line 132 "modules.nw"
 static char *lastfilename = 0;
@@ -81,12 +81,12 @@
     struct parent thismodule; /* the value only matters when we're expanding a module */
 
     
-#line 219 "modules.nw"
+#line 225 "modules.nw"
 thismodule.this = mp;
 thismodule.parent = parent;
 #line 153 "modules.nw"
     
-#line 222 "modules.nw"
+#line 228 "modules.nw"
 if (seekcycle(mp, parent)) {
     errormsg(Error, "<<%s>>", mp->name);
     return Error;
@@ -111,11 +111,12 @@
 #line 157 "modules.nw"
                                             ;  break;
             case MODULE:  
-#line 201 "modules.nw"
+#line 206 "modules.nw"
 newmod = lookup(p->contents);
 if (newmod==NULL) {
-    errormsg (Error, "undefined chunk name: <<%s>>", p->contents);
+    errormsg (Error, "ignoring undefined chunk name: <<%s>>", p->contents);
     error=Error;
+    printf("<<%s>>",p->contents);
 } else {
     int retcode;
     if (*locformat == 0 && partial_distance == 0) {
@@ -142,7 +143,7 @@
     }
     return error;
 }
-#line 229 "modules.nw"
+#line 235 "modules.nw"
 static int seekcycle(Module mp, Parent parent) {
     if (parent == NULL) {
         return 0;
@@ -155,14 +156,14 @@
         return 0;
     }
 }
-#line 251 "modules.nw"
+#line 257 "modules.nw"
 int printloc(FILE *fp, char *fmt, Location loc, int partial) {
     char *p;
     if (*fmt
     && (loc.filename!=lastfilename || lastlineno != loc.lineno)) {
         if (partial) putc('\n',fp);
         
-#line 263 "modules.nw"
+#line 269 "modules.nw"
 for (p = fmt; *p; p++) {
     if (*p == '%') {
         switch (*++p) {
@@ -177,35 +178,35 @@
                           p += 2;
                         } else
                           
-#line 283 "modules.nw"
+#line 289 "modules.nw"
 { static int complained = 0;
   if (!complained) {
     errormsg(Error,"Bad format sequence ``%%%c'' in -L%s",*p,fmt);
     complained = 1;
   }
 }
-#line 277 "modules.nw"
+#line 283 "modules.nw"
                       break;            
             default:  
-#line 283 "modules.nw"
+#line 289 "modules.nw"
 { static int complained = 0;
   if (!complained) {
     errormsg(Error,"Bad format sequence ``%%%c'' in -L%s",*p,fmt);
     complained = 1;
   }
 }
-#line 278 "modules.nw"
+#line 284 "modules.nw"
                                                                 break;
         }
     } else putc(*p, fp);
 }
-#line 257 "modules.nw"
+#line 263 "modules.nw"
         lastfilename = loc.filename;
         lastlineno = loc.lineno;
         return 1;
     } else return 0;
 }
-#line 309 "modules.nw"
+#line 315 "modules.nw"
 void remove_final_newline (Module mp) {
         /* remove trailing newline that must be in module */
     if (mp->tail==NULL) /* module has no text */
