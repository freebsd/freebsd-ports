--- src/objects/player.cpp.orig	2013-12-19 22:20:16.890052259 +0400
+++ src/objects/player.cpp	2013-12-19 22:20:57.089132087 +0400
@@ -45,7 +45,7 @@
 	Node->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
 	Node->setMaterialFlag(EMF_LIGHTING, false);
 	Node->setMaterialType(EMT_ONETEXTURE_BLEND);
-	Node->getMaterial(0).MaterialTypeParam = pack_texureBlendFunc(EBF_ONE, EBF_ONE);
+	Node->getMaterial(0).MaterialTypeParam = pack_textureBlendFunc(EBF_ONE, EBF_ONE);
 
 	// Light
 	//Light = irrScene->addLightSceneNode(0, core::vector3df(0.0f, 0.0f, 0.0f), video::SColorf(0.2f, 0.2f, 1.0f), 20.0f);
@@ -57,7 +57,7 @@
 	InnerNode->setMaterialFlag(EMF_ZBUFFER, false);
 	InnerNode->setMaterialTexture(0, irrDriver->getTexture("/home/amdmi3/projects/freebsd/ports/games/irrlamb/prefix/share/irrlamb/textures/player_glow0.png"));
 	InnerNode->setMaterialType(EMT_ONETEXTURE_BLEND);
-	InnerNode->getMaterial(0).MaterialTypeParam = pack_texureBlendFunc(EBF_ONE, EBF_ONE);
+	InnerNode->getMaterial(0).MaterialTypeParam = pack_textureBlendFunc(EBF_ONE, EBF_ONE);
 
 	// Particle system
 	IParticleSystemSceneNode *ParticleSystem = irrScene->addParticleSystemSceneNode(false, Node);
