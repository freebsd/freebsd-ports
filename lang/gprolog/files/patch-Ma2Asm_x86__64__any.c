--- Ma2Asm/x86_64_any.c.orig	2021-07-07 17:13:02.000000000 +0700
+++ Ma2Asm/x86_64_any.c	2021-07-11 03:18:18.347365000 +0700
@@ -232,8 +232,8 @@ Asm_Start(void)
   strcpy(asm_reg_cp, Off_Reg_Bank(MAP_OFFSET_CP));
 #endif
 
-#if defined(M_darwin) || defined(M_bsd)
-  pic_code = TRUE;  		/* NB: on darwin and BSD everything is PIC code */
+#if defined(M_darwin)
+  pic_code = TRUE;  		/* NB: on darwin everything is PIC code */
 #elif defined(M_linux) && __GNUC__ >= 6 /* gcc >= 6 needs PIC for linux */
   pic_code = FALSE;
 #elif defined(_WIN32)
@@ -1242,9 +1242,9 @@ Dico_Long(LongInf *l)
       size_bytes = l->value * 8;
 #ifdef M_darwin
       if (!l->global)
-        Label_Printf(".zerofill __DATA,__bss," UN "%s,%" PL_FMT_d ",4", l->name, size_bytes);
+        Label_Printf(".zerofill __DATA,__bss," UN "%s,%" PL_FMT_d ",3", l->name, size_bytes);
       else
-        Inst_Printf(".comm", UN "%s,%" PL_FMT_d ",4", l->name, size_bytes);
+        Inst_Printf(".comm", UN "%s,%" PL_FMT_d ",3", l->name, size_bytes);
 #else
 #if defined(M_linux) || defined(M_sco) || defined(M_solaris) || defined(M_bsd)
       if (!l->global)
@@ -1268,11 +1268,6 @@ Dico_Long(LongInf *l)
     case INITIAL_VALUE:
       if (l->global)
         Inst_Printf(".globl", UN "%s", l->name);
-#ifdef M_darwin
-      Inst_Printf(".align", "3");
-#else
-      Inst_Printf(".align", "8");
-#endif
 #if !(defined(M_darwin) || defined(_WIN32))
       Inst_Printf(".size", UN "%s,8", l->name);
 #endif
