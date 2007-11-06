--- gcc/config/arm/arm.c.orig	Thu Jan 25 07:03:24 2001
+++ gcc/config/arm/arm.c	Fri Nov  2 20:35:20 2007
@@ -281,7 +281,7 @@
       
       if (ptr->string != NULL && ptr->string[0] != '\0')
         {
-	  struct processors * sel;
+	  const struct processors * sel;
 
           for (sel = ptr->processors; sel->name != NULL; sel ++)
             if (streq (ptr->string, sel->name))
@@ -527,7 +527,7 @@
   if ((TARGET_SOFT_FLOAT || arm_fpu != FP_HARD) && (tune_flags & FL_MODE32) == 0)
     flag_schedule_insns = flag_schedule_insns_after_reload = 0;
   
-  arm_prog_mode = TARGET_APCS_32 ? PROG_MODE_PROG32 : PROG_MODE_PROG26;
+  arm_prgmode = TARGET_APCS_32 ? PROG_MODE_PROG32 : PROG_MODE_PROG26;
   
   if (structure_size_string != NULL)
     {
