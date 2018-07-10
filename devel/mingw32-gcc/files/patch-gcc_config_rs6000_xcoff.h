--- gcc/config/rs6000/xcoff.h.orig	2013-02-01 14:14:05 UTC
+++ gcc/config/rs6000/xcoff.h
@@ -271,7 +271,7 @@
 #define SKIP_ASM_OP "\t.space "
 
 #define ASM_OUTPUT_SKIP(FILE,SIZE)  \
-  fprintf (FILE, "%s"HOST_WIDE_INT_PRINT_UNSIGNED"\n", SKIP_ASM_OP, (SIZE))
+  fprintf (FILE, "%s" HOST_WIDE_INT_PRINT_UNSIGNED "\n", SKIP_ASM_OP, (SIZE))
 
 /* This says how to output an assembler line
    to define a global common symbol.  */
@@ -282,12 +282,12 @@
   do { fputs (COMMON_ASM_OP, (FILE));			\
        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\
        if ((ALIGN) > 32)				\
-	 fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n", (SIZE), \
+	 fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n", (SIZE), \
 		  floor_log2 ((ALIGN) / BITS_PER_UNIT)); \
        else if ((SIZE) > 4)				\
-         fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",3\n", (SIZE)); \
+         fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",3\n", (SIZE)); \
        else						\
-	 fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE)); \
+	 fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE)); \
   } while (0)
 
 /* This says how to output an assembler line
@@ -304,14 +304,14 @@
   do { fputs (LOCAL_COMMON_ASM_OP, (FILE));			\
        RS6000_OUTPUT_BASENAME ((FILE), (NAME));			\
        if ((ALIGN) > 32)					\
-	 fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%s,%u\n",	\
+	 fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%s,%u\n",	\
 		  (SIZE), xcoff_bss_section_name,			\
 		  floor_log2 ((ALIGN) / BITS_PER_UNIT));		\
        else if ((SIZE) > 4)					\
-	 fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%s,3\n",	\
+	 fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%s,3\n",	\
 		  (SIZE), xcoff_bss_section_name);		\
        else							\
-	 fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%s\n",	\
+	 fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%s\n",	\
 		  (SIZE), xcoff_bss_section_name);		\
      } while (0)
 #endif
@@ -319,7 +319,7 @@
 #define ASM_OUTPUT_LOCAL(FILE, NAME, SIZE, ROUNDED)	\
   do { fputs (LOCAL_COMMON_ASM_OP, (FILE));		\
        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\
-       fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%s\n", \
+       fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%s\n", \
 		(TARGET_32BIT ? (SIZE) : (ROUNDED)),	\
 		xcoff_bss_section_name);		\
      } while (0)
@@ -328,7 +328,7 @@
 #define ASM_OUTPUT_TLS_COMMON(FILE, DECL, NAME, SIZE)	\
   do { fputs(COMMON_ASM_OP, (FILE));			\
        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\
-       fprintf ((FILE), "[UL],"HOST_WIDE_INT_PRINT_UNSIGNED"\n", \
+       fprintf ((FILE), "[UL]," HOST_WIDE_INT_PRINT_UNSIGNED "\n", \
        (SIZE));						\
   } while (0)
 #endif
