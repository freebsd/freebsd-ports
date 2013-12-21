--- src/objects/orb.cpp.orig	2013-12-19 22:19:20.406056087 +0400
+++ src/objects/orb.cpp	2013-12-19 22:19:55.234053221 +0400
@@ -40,7 +40,7 @@
 	else
 		Node->setMaterialTexture(0, irrDriver->getTexture("/home/amdmi3/projects/freebsd/ports/games/irrlamb/prefix/share/irrlamb/textures/orb_outer0.png"));
 	Node->setMaterialType(EMT_ONETEXTURE_BLEND);
-	Node->getMaterial(0).MaterialTypeParam = pack_texureBlendFunc(EBF_ONE, EBF_ONE);
+	Node->getMaterial(0).MaterialTypeParam = pack_textureBlendFunc(EBF_ONE, EBF_ONE);
 	
 	// Create glow
 	//GlowColor = SColor(255, 255, 240, 130);
@@ -50,7 +50,7 @@
 	InnerNode->setMaterialFlag(EMF_LIGHTING, false);
 	InnerNode->setMaterialFlag(EMF_ZBUFFER, false);
 	InnerNode->setMaterialType(EMT_ONETEXTURE_BLEND);
-	InnerNode->getMaterial(0).MaterialTypeParam = pack_texureBlendFunc(EBF_ONE, EBF_ONE);
+	InnerNode->getMaterial(0).MaterialTypeParam = pack_textureBlendFunc(EBF_ONE, EBF_ONE);
 	if(Template->Textures[1] != "")
 		InnerNode->setMaterialTexture(0, irrDriver->getTexture(Template->Textures[1].c_str()));
 	else
