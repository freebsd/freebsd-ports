--- modules/tk/tk.c.orig	2013-06-03 18:38:51.000000000 +0200
+++ modules/tk/tk.c	2013-06-03 18:43:27.000000000 +0200
@@ -369,9 +369,9 @@
     }
   }
   if (!locked) acquire_lock();
-  if (trace || (int)clientData) {
+  if (trace || clientData != NULL) {
     int val;
-    if ((int)clientData && check_trace(buf, &val)) {
+    if (clientData != NULL && check_trace(buf, &val)) {
       clear_buf(&buf, &bufsz);
       Tcl_AppendResult(interp, trace?"1":"0", NULL);
       trace = val;
@@ -471,7 +471,7 @@
     return dequeue();
 }
 
-static void set_result(char *s)
+static void set_result(const char *s)
 {
   tld_result = malloc(strlen(s)+1);
   if (tld_result) strcpy(tld_result, s);
@@ -481,14 +481,16 @@
 {
   int status;
   char *cmd;
+  const char *res;
   tld_result = NULL;
   if (!tld_interp) return 0;
   cmd = malloc(strlen(s)+1);
   if (!cmd) return 0;
   strcpy(cmd, s);
   status = Tcl_Eval(tld_interp, cmd);
-  if (tld_interp && tld_interp->result && *tld_interp->result)
-    set_result(tld_interp->result);
+  res = Tcl_GetStringResult(tld_interp);
+  if (tld_interp && res && *res)
+    set_result(res);
   else if (status == TCL_BREAK)
     set_result("invoked \"break\" outside of a loop");
   else if (status == TCL_CONTINUE)
@@ -506,6 +508,7 @@
 {
   Tk_Window mainw;
   tld_result = NULL;
+  const char *res;
   if (tld_interp) return 1;
   /* Just to be safe, if Tcl has been compiled without thread support then we
      only allow a single interpreter in the main thread. */
@@ -516,8 +519,9 @@
   pthread_setspecific(interp_key, tld_interp);
 #endif
   if (Tcl_Init(tld_interp) != TCL_OK) {
-    if (tld_interp->result && *tld_interp->result)
-      set_result(tld_interp->result);
+    res = Tcl_GetStringResult(tld_interp);  
+    if (res && *res)
+      set_result(res);
     else
       set_result("error initializing Tcl");
     tk_stop();
@@ -533,8 +537,9 @@
   /* oddly, there are no `env' variables passed, and this one is needed */
   Tcl_SetVar2(tld_interp, "env", "DISPLAY", getenv("DISPLAY"), TCL_GLOBAL_ONLY);
   if (Tk_Init(tld_interp) != TCL_OK) {
-    if (tld_interp->result && *tld_interp->result)
-      set_result(tld_interp->result);
+    res = Tcl_GetStringResult(tld_interp);
+    if (res && *res)
+      set_result(res);
     else
       set_result("error initializing Tk");
     tk_stop();
