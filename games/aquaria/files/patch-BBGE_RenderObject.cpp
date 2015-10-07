https://github.com/AquariaOSE/Aquaria/pull/19

--- BBGE/RenderObject.cpp.orig	2015-08-16 13:19:19 UTC
+++ BBGE/RenderObject.cpp
@@ -316,10 +316,9 @@ static glm::mat4 matrixChain(const Rende
 	);
 
 	if (ro->isfh())
-		tranformMatrix *= glm::rotate(180.0f, 0.0f, 1.0f, 0.0f);
-
-	tranformMatrix *= glm::translate(ro->internalOffset.x, ro->internalOffset.y, 0.0f);
+		tranformMatrix *= glm::rotate(180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
 
+	tranformMatrix *= glm::translate(glm::vec3(ro->internalOffset.x, ro->internalOffset.y, 0.0f));
 	return tranformMatrix;
 }
 #else
