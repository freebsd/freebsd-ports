--- opcodes/tic54x-dis.c.orig	2013-03-07 10:46:52.000000000 +0100
+++ opcodes/tic54x-dis.c	2013-03-07 12:05:19.000000000 +0100
@@ -168,14 +168,9 @@
 }
 
 int
-print_instruction (info, memaddr, opcode, tm_name, tm_operands, size, ext)
-  disassemble_info *info;
-  bfd_vma memaddr;
-  unsigned short opcode;
-  const char *tm_name;
-  const enum optype tm_operands[];
-  int size;
-  int ext;
+print_instruction (disassemble_info * info, bfd_vma memaddr,
+  unsigned short opcode, const char *tm_name,
+  const enum optype tm_operands[], int size, int ext)
 {
   static int n;
   /* string storage for multiple operands */
@@ -468,6 +463,7 @@
   return 1;
 }
 
+/*
 static int
 print_parallel_instruction (info, memaddr, opcode, ptm, size)
   disassemble_info *info;
@@ -475,6 +471,11 @@
   unsigned short opcode;
   const insn_template *ptm;
   int size;
+*/
+static int
+print_parallel_instruction (disassemble_info *info,
+  bfd_vma memaddr, unsigned short opcode, 
+  const insn_template * ptm, int size)
 {
   print_instruction (info, memaddr, opcode,
                      ptm->name, ptm->operand_types, size, 0);
@@ -484,10 +485,8 @@
 }
 
 static int
-sprint_dual_address (info, buf, code)
-  disassemble_info *info ATTRIBUTE_UNUSED;
-  char buf[];
-  unsigned short code;
+sprint_dual_address ( disassemble_info *info ATTRIBUTE_UNUSED,
+  char buf[], unsigned short code)
 {
   const char *formats[] = {
     "*ar%d",
@@ -499,10 +498,8 @@
 }
 
 static int
-sprint_indirect_address (info, buf, opcode)
-  disassemble_info *info ATTRIBUTE_UNUSED;
-  char buf[];
-  unsigned short opcode;
+sprint_indirect_address (disassemble_info * info ATTRIBUTE_UNUSED,
+  char buf[], unsigned short opcode)
 {
   const char *formats[] = {
     "*ar%d",
@@ -522,10 +519,8 @@
 }
 
 static int
-sprint_direct_address (info, buf, opcode)
-  disassemble_info *info ATTRIBUTE_UNUSED;
-  char buf[];
-  unsigned short opcode;
+sprint_direct_address ( disassemble_info *info ATTRIBUTE_UNUSED,
+  char buf[], unsigned short opcode)
 {
   /* FIXME -- look up relocation if available */
   return sprintf (buf, "DP+0x%02x", (int) (opcode & 0x7F));
@@ -552,10 +547,8 @@
 }
 
 static int
-sprint_cc2 (info, buf, opcode)
-  disassemble_info *info ATTRIBUTE_UNUSED;
-  char *buf;
-  unsigned short opcode;
+sprint_cc2 (disassemble_info *info ATTRIBUTE_UNUSED,
+  char *buf, unsigned short opcode)
 {
   const char *cc2[] = {
     "??", "??", "ageq", "alt", "aneq", "aeq", "agt", "aleq",
@@ -565,10 +558,8 @@
 }
 
 static int
-sprint_condition (info, buf, opcode)
-  disassemble_info *info ATTRIBUTE_UNUSED;
-  char *buf;
-  unsigned short opcode;
+sprint_condition (disassemble_info *info ATTRIBUTE_UNUSED,
+  char *buf, unsigned short opcode)
 {
   char *start = buf;
   const char *cmp[] = {
