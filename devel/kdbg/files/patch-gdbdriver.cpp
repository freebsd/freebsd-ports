--- kdbg/gdbdriver.cpp.orig	2006-11-18 22:24:56.000000000 +0200
+++ kdbg/gdbdriver.cpp	2007-09-17 21:48:07.000000000 +0300
@@ -301,7 +301,7 @@
 	    }
 	    // use a feasible core-file command
 	    if (m_gdbMajor > 4 || (m_gdbMajor == 4 && m_gdbMinor >= 16)) {
-		cmds[DCcorefile].fmt = "target core %s\n";
+		cmds[DCcorefile].fmt = "target FreeBSD-core %s\n";
 	    } else {
 		cmds[DCcorefile].fmt = "core-file %s\n";
 	    }
