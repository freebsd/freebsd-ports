--- gdb/xtensa-tdep.h.orig	2018-03-15 16:33:53.194056000 +0100
+++ gdb/xtensa-tdep.h	2018-03-15 16:37:44.151472000 +0100
@@ -130,7 +130,7 @@
 	 ct, bsz, sz, al, tnum, flg, cp, mas, fet, sto},
 #define XTREG_END \
   {0, 0, (xtensa_register_type_t) 0, (xtensa_register_group_t) 0,	\
-   0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
+   0, 0, 0, 0, static_cast<unsigned int>(-1), 0, 0, 0, 0, 0},
 
 #define XTENSA_REGISTER_FLAGS_PRIVILEGED	0x0001
 #define XTENSA_REGISTER_FLAGS_READABLE		0x0002
@@ -228,7 +228,7 @@
 #define XTENSA_GDBARCH_TDEP_INSTANTIATE(rmap,spillsz)			\
   {									\
     0,				/* target_flags */			\
-    -1,				/* spill_location */			\
+    static_cast<unsigned int>(-1),	/* spill_location */			\
     (spillsz),			/* spill_size */			\
     0,				/* unused */				\
     (XSHAL_ABI == XTHAL_ABI_CALL0					\
