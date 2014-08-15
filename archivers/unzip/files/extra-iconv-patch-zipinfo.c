--- zipinfo.c.orig	2009-02-08 17:04:30 UTC
+++ zipinfo.c
@@ -457,6 +457,10 @@ int zi_opts(__G__ pargc, pargv)
     int    tflag_slm=TRUE, tflag_2v=FALSE;
     int    explicit_h=FALSE, explicit_t=FALSE;
 
+#ifdef UNIX
+    extern char OEM_CP[MAX_CP_NAME];
+    extern char ISO_CP[MAX_CP_NAME];
+#endif
 
 #ifdef MACOS
     uO.lflag = LFLAG;         /* reset default on each call */
@@ -501,6 +505,35 @@ int zi_opts(__G__ pargc, pargv)
                             uO.lflag = 0;
                     }
                     break;
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
                 case 'l':      /* longer form of "ls -l" type listing */
                     if (negative)
                         uO.lflag = -2, negative = 0;
@@ -521,6 +554,35 @@ int zi_opts(__G__ pargc, pargv)
                         G.M_flag = TRUE;
                     break;
 #endif
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
                 case 's':      /* default:  shorter "ls -l" type listing */
                     if (negative)
                         uO.lflag = -2, negative = 0;
