--- unzip.c.orig	2009-04-16 18:26:52 UTC
+++ unzip.c
@@ -327,11 +327,21 @@ static ZCONST char Far ZipInfoUsageLine2
   -2  just filenames but allow -h/-t/-z  -l  long Unix \"ls -l\" format\n\
                                          -v  verbose, multi-page format\n";
 
+#ifndef UNIX
 static ZCONST char Far ZipInfoUsageLine3[] = "miscellaneous options:\n\
   -h  print header line       -t  print totals for listed files or for all\n\
   -z  print zipfile comment   -T  print file times in sortable decimal format\
 \n  -C  be case-insensitive   %s\
   -x  exclude filenames that follow from listing\n";
+#else /* UNIX */
+static ZCONST char Far ZipInfoUsageLine3[] = "miscellaneous options:\n\
+  -h  print header line       -t  print totals for listed files or for all\n\
+  -z  print zipfile comment  %c-T%c print file times in sortable decimal format\
+\n %c-C%c be case-insensitive   %s\
+  -x  exclude filenames that follow from listing\n\
+  -O CHARSET  specify a character encoding for DOS, Windows and OS/2 archives\n\
+  -I CHARSET  specify a character encoding for UNIX and other archives\n";
+#endif /* !UNIX */
 #ifdef MORE
    static ZCONST char Far ZipInfoUsageLine4[] =
      "  -M  page output through built-in \"more\"\n";
@@ -665,6 +675,17 @@ modifiers:\n\
   -U  use escapes for all non-ASCII Unicode  -UU ignore any Unicode fields\n\
   -C  match filenames case-insensitively     -L  make (some) names \
 lowercase\n %-42s  -V  retain VMS version numbers\n%s";
+#elif (defined UNIX)
+static ZCONST char Far UnzipUsageLine4[] = "\
+modifiers:\n\
+  -n  never overwrite existing files         -q  quiet mode (-qq => quieter)\n\
+  -o  overwrite files WITHOUT prompting      -a  auto-convert any text files\n\
+  -j  junk paths (do not make directories)   -aa treat ALL files as text\n\
+  -U  use escapes for all non-ASCII Unicode  -UU ignore any Unicode fields\n\
+  -C  match filenames case-insensitively     -L  make (some) names \
+lowercase\n %-42s  -V  retain VMS version numbers\n%s\
+  -O CHARSET  specify a character encoding for DOS, Windows and OS/2 archives\n\
+  -I CHARSET  specify a character encoding for UNIX and other archives\n\n";
 #else /* !VMS */
 static ZCONST char Far UnzipUsageLine4[] = "\
 modifiers:\n\
@@ -803,6 +824,10 @@ int unzip(__G__ argc, argv)
 #endif /* UNICODE_SUPPORT */
 
 
+#ifdef UNIX
+    init_conversion_charsets();
+#endif
+
 #if (defined(__IBMC__) && defined(__DEBUG_ALLOC__))
     extern void DebugMalloc(void);
 
@@ -1336,6 +1361,11 @@ int uz_opts(__G__ pargc, pargv)
     argc = *pargc;
     argv = *pargv;
 
+#ifdef UNIX
+    extern char OEM_CP[MAX_CP_NAME];
+    extern char ISO_CP[MAX_CP_NAME];
+#endif
+    
     while (++argv, (--argc > 0 && *argv != NULL && **argv == '-')) {
         s = *argv + 1;
         while ((c = *s++) != 0) {    /* "!= 0":  prevent Turbo C warning */
@@ -1517,6 +1547,35 @@ int uz_opts(__G__ pargc, pargv)
                     }
                     break;
 #endif  /* MACOS */
+#ifdef UNIX
+    			case ('I'):
+                    if (negative) {
+                        Info(slide, 0x401, ((char *)slide,
+                          "error:  encodings can't be negated"));
+                        return(PK_PARAM);
+    				} else {
+    					if(*s) { /* Handle the -Icharset case */
+    						/* Assume that charsets can't start with a dash to spot arguments misuse */
+    						if(*s == '-') { 
+    	                        Info(slide, 0x401, ((char *)slide,
+        		                  "error:  a valid character encoding should follow the -I argument"));
+    	                        return(PK_PARAM); 
+    						}
+    						strncpy(ISO_CP, s, sizeof(ISO_CP));
+    					} else { /* -I charset */
+    						++argv;
+    						if(!(--argc > 0 && *argv != NULL && **argv != '-')) {
+    	                        Info(slide, 0x401, ((char *)slide,
+        		                  "error:  a valid character encoding should follow the -I argument"));
+    	                        return(PK_PARAM); 
+    						}
+    						s = *argv;
+    						strncpy(ISO_CP, s, sizeof(ISO_CP));
+    					}
+    					while(*(++s)); /* No params straight after charset name */
+    				}
+    				break;
+#endif /* ?UNIX */
                 case ('j'):    /* junk pathnames/directory structure */
                     if (negative)
                         uO.jflag = FALSE, negative = 0;
@@ -1592,6 +1651,35 @@ int uz_opts(__G__ pargc, pargv)
                     } else
                         ++uO.overwrite_all;
                     break;
+#ifdef UNIX
+    			case ('O'):
+                    if (negative) {
+                        Info(slide, 0x401, ((char *)slide,
+                          "error:  encodings can't be negated"));
+                        return(PK_PARAM);
+    				} else {
+    					if(*s) { /* Handle the -Ocharset case */
+    						/* Assume that charsets can't start with a dash to spot arguments misuse */
+    						if(*s == '-') { 
+    	                        Info(slide, 0x401, ((char *)slide,
+        		                  "error:  a valid character encoding should follow the -I argument"));
+    	                        return(PK_PARAM); 
+    						}
+    						strncpy(OEM_CP, s, sizeof(OEM_CP));
+    					} else { /* -O charset */
+    						++argv;
+    						if(!(--argc > 0 && *argv != NULL && **argv != '-')) {
+    	                        Info(slide, 0x401, ((char *)slide,
+        		                  "error:  a valid character encoding should follow the -O argument"));
+    	                        return(PK_PARAM); 
+    						}
+    						s = *argv;
+    						strncpy(OEM_CP, s, sizeof(OEM_CP));
+    					}
+    					while(*(++s)); /* No params straight after charset name */
+    				}
+    				break;
+#endif /* ?UNIX */
                 case ('p'):    /* pipes:  extract to stdout, no messages */
                     if (negative) {
                         uO.cflag = FALSE;
