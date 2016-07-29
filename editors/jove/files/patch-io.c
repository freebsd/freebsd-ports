--- io.c.orig	1996-03-07 17:34:42 UTC
+++ io.c
@@ -1193,10 +1193,16 @@ tmpinit()
 #endif
 		);
 	tfname = copystr(buf);
+#ifdef NO_MKSTEMP
 	tfname = mktemp(tfname);
+#endif
 #ifndef MSFILESYSTEM
+#ifndef NO_MKSTEMP
+	tmpfd = mkstemp(tfname);
+#else
 	(void) close(creat(tfname, 0600));
 	tmpfd = open(tfname, 2);
+#endif
 #else /* MSFILESYSTEM */
 	tmpfd = open(tfname, O_CREAT|O_EXCL|O_BINARY|O_RDWR, S_IWRITE|S_IREAD);
 #endif /* MSFILESYSTEM */
@@ -1240,9 +1246,9 @@ int	Jr_Len;		/* length of Just Read Line
 
 void
 #ifdef USE_PROTOTYPES
-getline proto((daddr addr, register char *buf))
+get_line proto((daddr addr, register char *buf))
 #else
-getline(addr, buf)
+get_line(addr, buf)
 daddr	addr;
 register char	*buf;
 #endif
