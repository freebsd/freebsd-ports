Index: glean/ttexenv.cpp
===================================================================
RCS file: /cvsroot/glean/glean/src/glean/ttexenv.cpp,v
retrieving revision 1.7
retrieving revision 1.6
diff -u -u -r1.7 -r1.6
--- glean/ttexenv.cpp	24 Sep 2003 16:28:08 -0000	1.7
+++ glean/ttexenv.cpp	31 May 2001 16:05:35 -0000	1.6
@@ -614,8 +614,6 @@
 	else
 		numModes = 4;
 
-	r.pass = true;
-
 	for (int fmt = 0; fmt < 6; fmt++) {
 		const GLenum format = FormatEnums[fmt];
 		const char *formatName = FormatNames[fmt];
@@ -632,7 +630,7 @@
 						envName, formatName,
 						COLORS, colors, envColor, w)) {
 						r.pass = false;
-						break;
+						return;
 					}
 				}
 			}
@@ -642,10 +640,14 @@
 					envName, formatName,
 					COLORS, colors, colors[0], w)) {
 					r.pass = false;
+					return;
 				}
 			}
 		}
 	}
+
+	r.pass = true;
+
 } // TexEnvTest::runOne
 
 
