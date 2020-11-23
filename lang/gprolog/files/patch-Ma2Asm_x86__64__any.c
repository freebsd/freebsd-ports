--- Ma2Asm/x86_64_any.c.orig	2018-10-23 15:17:17 UTC
+++ Ma2Asm/x86_64_any.c
@@ -112,6 +112,9 @@
  * Global Variables                *
  *---------------------------------*/
 
+int can_produce_pic_code = 1;	/* overwritte var of ma2asm.c */
+extern int pic_code;
+
 static double dbl_tbl[MAX_DOUBLES_IN_PRED];
 static int nb_dbl = 0;
 static int dbl_lc_no = 0;
@@ -149,7 +152,6 @@ static const char *fpr_arg[MAX_FPR_ARGS]
 #endif
           /* variables for ma_parser.c / ma2asm.c */
 
-int can_produce_pic_code = 1;
 char *comment_prefix = "#";
 #ifdef M_x86_64_darwin
 char *local_symb_prefix = "L";
@@ -210,10 +212,8 @@ Asm_Start(void)
   strcpy(asm_reg_cp, Off_Reg_Bank(MAP_OFFSET_CP));
 #endif
 
-#if defined(M_x86_64_darwin) || defined(M_x86_64_bsd)
-  pic_code = 1;                 /* NB: on darwin and BSD everything is PIC code */
-#elif defined(M_x86_64_linux) && __GNUC__ >= 6 /* gcc >= 6 needs PIC for linux */
-  pic_code = 1;
+#ifdef M_x86_64_darwin
+  pic_code = 1;			/* NB: on darwin everything is PIC code */
 #elif defined(_WIN32)
   pic_code = 0;			/* NB: on MinGW nothing is needed for PIC code */
 #endif
@@ -1199,9 +1199,9 @@ Dico_Long(char *name, int global, VType 
       size_bytes = value * 8;
 #ifdef M_x86_64_darwin
       if (!global)
-        Label_Printf(".zerofill __DATA,__bss," UN "%s,%" PL_FMT_d ",4", name, size_bytes);
+        Label_Printf(".zerofill __DATA,__bss," UN "%s,%" PL_FMT_d ",3", name, size_bytes);
       else
-        Inst_Printf(".comm", UN "%s,%" PL_FMT_d ",4", name, size_bytes);
+        Inst_Printf(".comm", UN "%s,%" PL_FMT_d ",3", name, size_bytes);
 #else
 #if defined(M_x86_64_linux) || defined(M_x86_64_sco) || \
     defined(M_x86_64_solaris) || defined(M_x86_64_bsd)
@@ -1226,11 +1226,6 @@ Dico_Long(char *name, int global, VType 
     case INITIAL_VALUE:
       if (global)
         Inst_Printf(".globl", UN "%s", name);
-#ifdef M_x86_64_darwin
-      Inst_Printf(".align", "3");
-#else
-      Inst_Printf(".align", "8");
-#endif
 #if !(defined(M_x86_64_darwin) || defined(_WIN32))
       Inst_Printf(".size", UN "%s,8", name);
 #endif
