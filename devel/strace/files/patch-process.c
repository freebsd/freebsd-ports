--- process.c.old	Thu Sep 27 22:08:22 2001
+++ process.c	Thu Sep 27 22:08:57 2001
@@ -1771,7 +1771,9 @@
 	{ PT_READ_D,		"PT_READ_D"		},
 	{ PT_WRITE_I,		"PT_WRITE_I"		},
 	{ PT_WRITE_D,		"PT_WRITE_D"		},
-	{ PT_READ_U,		"PT_WRITE_U"		},
+#ifdef PT_READ_U
+	{ PT_READ_U,		"PT_READ_U"		},
+#endif
 	{ PT_CONTINUE,		"PT_CONTINUE"		},
 	{ PT_KILL,		"PT_KILL"		},
 	{ PT_STEP,		"PT_STEP"		},
