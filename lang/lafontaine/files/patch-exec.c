--- src/exec.c.orig	Fri Oct 25 11:28:43 2002
+++ src/exec.c	Mon Oct  2 20:50:35 2006
@@ -109,6 +109,7 @@
   { 47031, 47031, 47031}  //15 or
 };
 
+void exec_execute_proc(struct s_proc *proc);
 
 /**
    main execution function.<br>
@@ -265,7 +266,7 @@
  */
 struct s_instr *exec_moveforward(struct s_instr *instr)
 {
-  register int steps;
+  int steps;
 #ifdef DEBUG
   debug_append("  # executing exec_moveforward()\n");
 #endif
@@ -745,7 +746,7 @@
  */
 struct s_instr *exec_hazard(struct s_instr *instr)
 {
-  register guint maxvalue, hazvalue;
+  guint maxvalue, hazvalue;
 
 #ifdef DEBUG
   debug_append("  # executing exec_hazard()\n");
@@ -804,7 +805,7 @@
  */
 struct s_instr *exec_loopcnt(struct s_instr *instr)
 {
-  register gint loopcnt, startval;
+  gint loopcnt, startval;
 
 #ifdef DEBUG
   debug_append("  # executing exec_loopcnt()\n");
@@ -830,7 +831,7 @@
  */
 struct s_instr *exec_if(struct s_instr *instr)
 {
-  register gboolean condition;
+  gboolean condition;
   
 #ifdef DEBUG
   debug_append("  # executing exec_if()\n");
@@ -875,7 +876,7 @@
  */
 struct s_instr *exec_while(struct s_instr *instr)
 {
-  register gboolean condition;
+  gboolean condition;
 
 #ifdef DEBUG
   debug_append("  # executing exec_while()\n");
