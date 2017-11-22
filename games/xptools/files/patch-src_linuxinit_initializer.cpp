--- src/linuxinit/initializer.cpp.orig	2017-04-14 14:21:02 UTC
+++ src/linuxinit/initializer.cpp
@@ -102,9 +102,7 @@
 	}
 	m_init = true;
 	// Try to resolve /proc/self/exe first
-	if (!(m_abspath = canonicalize_file_name("/proc/self/exe")))
-		// Try argv[0]
-		if (!(m_abspath = canonicalize_file_name(*argv[0])))
+	if (!(m_abspath = *argv[0]))
 			goto critical;
 
 	temp = strdup(const_cast<const char* const>(m_abspath));
