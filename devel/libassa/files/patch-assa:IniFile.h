--- assa/IniFile.h.orig	Sat Sep 13 19:01:00 2003
+++ assa/IniFile.h	Thu Jan 29 09:05:01 2004
@@ -171,7 +171,7 @@
 
 		/** Return iterator past the last section.
 		 */
-		const_config_iterator sect_end () const { return m_config.end (); }
+		config_iterator sect_end () { return m_config.end (); }
 
 		/** Return number of sections in the cache
 		 */
