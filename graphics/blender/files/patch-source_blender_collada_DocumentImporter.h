--- source/blender/collada/DocumentImporter.h.orig	2018-12-03 07:38:12 UTC
+++ source/blender/collada/DocumentImporter.h
@@ -107,6 +107,8 @@ public:
 	bool writeAnimation(const COLLADAFW::Animation*);
 
 	bool writeAnimationList(const COLLADAFW::AnimationList*);
+	
+	bool writeAnimationClip( const COLLADAFW::AnimationClip* );
 
 	bool writeGeometry(const COLLADAFW::Geometry*);
 
