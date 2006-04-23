--- src/main.cs.orig	Sun Feb 26 17:37:08 2006
+++ src/main.cs	Wed Apr  5 16:22:56 2006
@@ -142,6 +142,8 @@
 			}
 		} catch (DllNotFoundException de) {
 			/* noop */
+		} catch (EntryPointNotFoundException de) {
+		    	/* noop */
 		}
 	}
 }
