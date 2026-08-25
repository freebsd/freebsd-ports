--- talloc.c.orig	2019-03-21 10:12:32 UTC
+++ talloc.c
@@ -396,6 +396,9 @@ void talloc_lib_init(void) __attribute__
 void talloc_lib_init(void)
 {
 	uint32_t random_value;
+#if defined(HAVE_ARC4RANDOM)
+	random_value = arc4random();
+#else
 #if defined(HAVE_GETAUXVAL) && defined(AT_RANDOM)
 	uint8_t *p;
 	/*
@@ -429,6 +432,7 @@ void talloc_lib_init(void)
 		 */
 		random_value = ((uintptr_t)talloc_lib_init & 0xFFFFFFFF);
 	}
+#endif /* HAVE_ARC4RANDOM */
 	talloc_magic = random_value & ~TALLOC_FLAG_MASK;
 }
 #else
