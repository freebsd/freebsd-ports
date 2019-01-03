--- 3rdparty/libprojectm/Renderer/VideoEcho.cpp.orig	2018-12-05 17:16:34 UTC
+++ 3rdparty/libprojectm/Renderer/VideoEcho.cpp
@@ -77,10 +77,10 @@ void VideoEcho::Draw(RenderContext &context)
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
