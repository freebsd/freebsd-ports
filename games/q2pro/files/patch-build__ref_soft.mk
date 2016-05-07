--- build/ref_soft.mk.orig	Wed Feb 14 18:10:04 2007
+++ build/ref_soft.mk	Wed Feb 14 18:15:42 2007
@@ -43,6 +43,7 @@ SRCFILES = q_shared.c \
 	   sw_sird.c   \
 	   r_images.c
 
+ifdef USE_X86_ASM
 ASMFILES = r_aclipa.s \
 		 r_draw16.s \
 		 r_drawa.s  \
@@ -53,7 +54,10 @@ ASMFILES = r_aclipa.s \
 		 r_varsa.s  \
 		 d_polysa.s \
 		 sys_dosa.s
-		 		 
+else
+CFLAGS += -DC_ONLY
+endif
+
 RESFILES += ref_soft.rc
 
 SRCFILES_WIN32 = q_shwin.c
