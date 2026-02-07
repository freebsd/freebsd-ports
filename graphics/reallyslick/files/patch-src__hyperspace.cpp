--- src/hyperspace.cpp.orig	2009-05-17 07:41:52.000000000 +0900
+++ src/hyperspace.cpp	2009-05-21 18:05:29.000000000 +0900
@@ -144,6 +144,14 @@
 		first = 0;
 	}
 
+	aspectRatio = float(XStuff->windowWidth) / float(XStuff->windowHeight);
+	glViewport(0, 0, XStuff->windowWidth, XStuff->windowHeight);
+
+	// setup projection matrix
+	glMatrixMode(GL_PROJECTION);
+	glLoadIdentity();
+	gluPerspective(float(dFov), aspectRatio, 0.001f, 200.0f);
+	glGetDoublev(GL_PROJECTION_MATRIX, projMat);    
 	glMatrixMode(GL_MODELVIEW);
 
 	// Camera movements
