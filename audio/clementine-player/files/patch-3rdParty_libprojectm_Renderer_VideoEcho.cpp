--- 3rdparty/libprojectm/Renderer/VideoEcho.cpp.orig	2018-01-31 22:10:05.891427000 +0000
+++ 3rdparty/libprojectm/Renderer/VideoEcho.cpp	2018-01-31 22:14:31.332885000 +0000
@@ -77,10 +77,10 @@
 			default: flipx=1;flipy=1; break;
 		}
 
-		float pointsFlip[4][2] = {{-0.5*flipx, -0.5*flipy},
-					  {-0.5*flipx,  0.5*flipy},
-					  { 0.5*flipx,  0.5*flipy},
-					  { 0.5*flipx, -0.5*flipy}};
+		float pointsFlip[4][2] = {{static_cast<float>(-0.5)*flipx, static_cast<float>(-0.5)*flipy},
+					  {static_cast<float>(-0.5)*flipx,  static_cast<float>(0.5)*flipy},
+					  { static_cast<float>(0.5)*flipx,  static_cast<float>(0.5)*flipy},
+					  { static_cast<float>(0.5)*flipx, static_cast<float>(-0.5)*flipy}};
 
 		glVertexPointer(2,GL_FLOAT,0,pointsFlip);
 		glDrawArrays(GL_TRIANGLE_FAN,0,4);
