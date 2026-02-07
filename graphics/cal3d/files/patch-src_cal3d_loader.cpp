loader.cpp:899:12: error: cannot initialize return object of type 'CalCoreKeyframe *' with an rvalue of type 'bool'
    return false;
           ^~~~~
loader.cpp:1448:11: error: no viable conversion from returned value of type 'bool' to function return type 'CalCoreSkeletonPtr' (aka 'RefPtr<CalCoreSkeleton>')
                        return false;
                               ^~~~~
../../src/cal3d/refptr.h:16:9: note: candidate constructor not viable: no known conversion from 'bool' to 'CalCoreSkeleton *' for 1st argument
        RefPtr(T* ptr = 0)
        ^
../../src/cal3d/refptr.h:22:9: note: candidate constructor not viable: no known conversion from 'bool' to 'const RefPtr<CalCoreSkeleton> &' for 1st argument
        RefPtr(const RefPtr<T>& ptr)
        ^
[...]

--- src/cal3d/loader.cpp.orig	2006-08-22 12:42:11 UTC
+++ src/cal3d/loader.cpp
@@ -896,7 +896,7 @@ CalCoreKeyframe* CalLoader::loadCoreKeyframe(CalDataSo
   if(!dataSrc.ok())
   {
     dataSrc.setError();
-    return false;
+    return 0;
   }
 
   // allocate a new core keyframe instance
@@ -1445,13 +1445,13 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(stricmp(skeleton->Attribute("MAGIC"),Cal::SKELETON_XMLFILE_MAGIC)!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		if(atoi(skeleton->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
 		{
 			CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		skeleton = skeleton->NextSiblingElement();
@@ -1460,19 +1460,19 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 	if(!skeleton || stricmp(skeleton->Value(),"SKELETON")!=0)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(skeleton->Attribute("MAGIC")!=NULL && stricmp(skeleton->Attribute("MAGIC"),Cal::SKELETON_XMLFILE_MAGIC)!=0)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(skeleton->Attribute("VERSION")!=NULL && atoi(skeleton->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
 	{
 		CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 
@@ -1490,7 +1490,7 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(stricmp(bone->Value(),"BONE")!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}    
 
 		std::string strName=bone->Attribute("NAME");
@@ -1502,7 +1502,7 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!translation || stricmp( translation->Value(),"TRANSLATION")!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		float tx, ty, tz;
@@ -1511,13 +1511,13 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!node)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}    
 		TiXmlText* translationdata = node->ToText();
 		if(!translationdata)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}    
 		str.clear();
 		str << translationdata->Value();
@@ -1529,7 +1529,7 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!rotation || stricmp(rotation->Value(),"ROTATION")!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		float rx, ry, rz, rw;
@@ -1538,13 +1538,13 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!node)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		TiXmlText* rotationdata = node->ToText();
 		if(!rotationdata)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		str.clear();
 		str << rotationdata->Value();
@@ -1557,7 +1557,7 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!rotation || stricmp(translationBoneSpace->Value(),"LOCALTRANSLATION")!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		float txBoneSpace, tyBoneSpace, tzBoneSpace;
@@ -1566,13 +1566,13 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!node)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		TiXmlText* translationBoneSpacedata = node->ToText();
 		if(!translationBoneSpacedata)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		str.clear();
 		str << translationBoneSpacedata->Value();
@@ -1584,7 +1584,7 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!rotationBoneSpace || stricmp(rotationBoneSpace->Value(),"LOCALROTATION")!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		float rxBoneSpace, ryBoneSpace, rzBoneSpace, rwBoneSpace;
@@ -1593,13 +1593,13 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!node)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		TiXmlText* rotationBoneSpacedata = node->ToText();
 		if(!rotationBoneSpacedata)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		str.clear();
 		str << rotationBoneSpacedata->Value();
@@ -1611,7 +1611,7 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!parent ||stricmp(parent->Value(),"PARENTID")!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 
@@ -1621,13 +1621,13 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 		if(!node)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		TiXmlText* parentid = node->ToText();
 		if(!parentid)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 		parentId = atoi(parentid->Value());
 
@@ -1673,7 +1673,7 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 			{
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
 				delete pCoreBone;
-				return false;
+				return 0;
 			}
 
 			TiXmlNode *node= child->FirstChild();
@@ -1681,14 +1681,14 @@ CalCoreSkeletonPtr CalLoader::loadXmlCoreSkeleton(cons
 			{
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
 				delete pCoreBone;
-				return false;
+				return 0;
 			}
 			TiXmlText* childid = node->ToText();
 			if(!childid)
 			{
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
 				delete pCoreBone;
-				return false;
+				return 0;
 			}
 
 			int childId = atoi(childid->Value());
@@ -1740,7 +1740,7 @@ CalCoreAnimationPtr CalLoader::loadXmlCoreAnimation(co
 	if(!animation)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(stricmp(animation->Value(),"HEADER")==0)
@@ -1748,13 +1748,13 @@ CalCoreAnimationPtr CalLoader::loadXmlCoreAnimation(co
 		if(stricmp(animation->Attribute("MAGIC"),Cal::ANIMATION_XMLFILE_MAGIC)!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		if(atoi(animation->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
 		{
 			CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		animation = animation->NextSiblingElement();
@@ -1763,19 +1763,19 @@ CalCoreAnimationPtr CalLoader::loadXmlCoreAnimation(co
 	if(!animation || stricmp(animation->Value(),"ANIMATION")!=0)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(animation->Attribute("MAGIC") !=NULL && stricmp(animation->Attribute("MAGIC"),Cal::ANIMATION_XMLFILE_MAGIC)!=0)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(animation->Attribute("VERSION")!=NULL && atoi(animation->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
 	{
 		CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	int trackCount= atoi(animation->Attribute("NUMTRACKS"));
@@ -1987,7 +1987,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 	if(!mesh)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(stricmp(mesh->Value(),"HEADER")==0)
@@ -1995,13 +1995,13 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 		if(stricmp(mesh->Attribute("MAGIC"),Cal::MESH_XMLFILE_MAGIC)!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		if(atoi(mesh->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
 		{
 			CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		mesh = mesh->NextSiblingElement();
@@ -2009,19 +2009,19 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 	if(!mesh || stricmp(mesh->Value(),"MESH")!=0)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(mesh->Attribute("MAGIC")!=NULL && stricmp(mesh->Attribute("MAGIC"),Cal::MESH_XMLFILE_MAGIC)!=0)
 	{
 		CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	if(mesh->Attribute("VERSION")!=NULL && atoi(mesh->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
 	{
 		CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-		return false;
+		return 0;
 	}
 
 	// get the number of submeshes
@@ -2044,7 +2044,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 		if(!submesh || stricmp(submesh->Value(),"SUBMESH")!=0)
 		{
 			CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-			return false;
+			return 0;
 		}
 
 		// get the material thread id of the submesh
@@ -2093,7 +2093,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}      
 
 			CalCoreSubmesh::Vertex Vertex;
@@ -2103,7 +2103,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}
 
 			node = pos->FirstChild();
@@ -2111,14 +2111,14 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}      
 			TiXmlText* posdata = node->ToText();
 			if(!posdata)
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}
 			str.clear();
 			str << posdata->Value();
@@ -2129,7 +2129,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}
 
 			node = norm->FirstChild();
@@ -2137,14 +2137,14 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}
 			TiXmlText* normdata = node->ToText();
 			if(!normdata)
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}
 			str.clear();
 			str << normdata->Value();
@@ -2158,14 +2158,14 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				TiXmlText* collapseid = node->ToText();
 				if(!collapseid)
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				Vertex.collapseId = atoi(collapseid->Value());
 
@@ -2174,7 +2174,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 
 				node = collapseCount->FirstChild();
@@ -2182,14 +2182,14 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				TiXmlText* collapseCountdata = node->ToText();
 				if(!collapseCountdata)
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				Vertex.faceCollapseCount= atoi(collapseCountdata->Value());
 				collapse = collapseCount->NextSiblingElement();        
@@ -2213,7 +2213,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 
 				node = texcoord->FirstChild();
@@ -2221,14 +2221,14 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				TiXmlText* texcoorddata = node->ToText();
 				if(!texcoorddata)
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				str.clear();
 				str << texcoorddata->Value();
@@ -2268,7 +2268,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 
 				node = influence->FirstChild();
@@ -2276,14 +2276,14 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				TiXmlText* influencedata = node->ToText();
 				if(!influencedata)
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 
 				Vertex.vectorInfluence[influenceId].boneId = atoi(influence->Attribute("ID"));
@@ -2309,21 +2309,21 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				node = physique->FirstChild();
 				if(!node)
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 				TiXmlText* physiquedata = node->ToText();
 				if(!physiquedata)
 				{
 					delete pCoreSubmesh;
 					CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-					return false;
+					return 0;
 				}
 
 				physicalProperty.weight = (float) atof(physiquedata->Value());
@@ -2348,7 +2348,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}
 			str.clear();
 			str << spring->Attribute("VERTEXID");
@@ -2373,7 +2373,7 @@ CalCoreMeshPtr CalLoader::loadXmlCoreMesh(const std::s
 			{
 				delete pCoreSubmesh;
 				CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-				return false;
+				return 0;
 			}
 
 			int tmp[3];
@@ -2443,7 +2443,7 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!material)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-        return false;
+        return 0;
   }
 
   if(stricmp(material->Value(),"HEADER")==0)
@@ -2451,13 +2451,13 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
     if(stricmp(material->Attribute("MAGIC"),Cal::MATERIAL_XMLFILE_MAGIC)!=0)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-          return false;
+          return 0;
     }
 
     if(atoi(material->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
     {
     CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-          return false;
+          return 0;
     }
 
     material = material->NextSiblingElement();
@@ -2466,19 +2466,19 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!material||stricmp(material->Value(),"MATERIAL")!=0)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-      return false;
+      return 0;
   }
 
   if(material->Attribute("MAGIC")!=NULL && stricmp(material->Attribute("MAGIC"),Cal::MATERIAL_XMLFILE_MAGIC)!=0)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-        return false;
+        return 0;
   }
 
   if(material->Attribute("VERSION") != NULL && atoi(material->Attribute("VERSION")) < Cal::EARLIEST_COMPATIBLE_FILE_VERSION )
   {
     CalError::setLastError(CalError::INCOMPATIBLE_FILE_VERSION, __FILE__, __LINE__, strFilename);
-        return false;
+        return 0;
   }
 
   CalCoreMaterialPtr pCoreMaterial = new CalCoreMaterial();
@@ -2492,7 +2492,7 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!ambient ||stricmp(ambient->Value(),"AMBIENT")!=0)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
 
   CalCoreMaterial::Color ambientColor; 
@@ -2500,13 +2500,13 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!node)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   TiXmlText* ambientdata = node->ToText();
   if(!ambientdata)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   str << ambientdata->Value();
   str >> r >> g >> b >> a;
@@ -2519,7 +2519,7 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!diffuse || stricmp(diffuse->Value(),"DIFFUSE")!=0)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
 
   CalCoreMaterial::Color diffuseColor; 
@@ -2527,13 +2527,13 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!node)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   TiXmlText* diffusedata = node->ToText();
   if(!diffusedata)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   str.clear();
   str << diffusedata->Value();
@@ -2548,7 +2548,7 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!specular||stricmp(specular->Value(),"SPECULAR")!=0)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
 
   CalCoreMaterial::Color specularColor; 
@@ -2556,13 +2556,13 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!node)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   TiXmlText* speculardata = node->ToText();
   if(!speculardata)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   str.clear();
   str << speculardata->Value();
@@ -2576,7 +2576,7 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!shininess||stricmp(shininess->Value(),"SHININESS")!=0)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
 
   float fshininess;
@@ -2584,13 +2584,13 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
   if(!node)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   TiXmlText* shininessdata = node->ToText();
   if(!shininessdata)
   {
     CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-    return false;
+    return 0;
   }
   fshininess = (float)atof(shininessdata->Value());
 
@@ -2609,7 +2609,7 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
     if(!map||stricmp(map->Value(),"MAP")!=0)
     {
       CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-      return false;
+      return 0;
     }
     
 
@@ -2617,14 +2617,14 @@ CalCoreMaterialPtr CalLoader::loadXmlCoreMaterial(cons
     if(!node)
     {
       CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-      return false;
+      return 0;
     }
 
     TiXmlText* mapfile = node->ToText();
     if(!mapfile)
     {
       CalError::setLastError(CalError::INVALID_FILE_FORMAT, __FILE__, __LINE__, strFilename);
-      return false;
+      return 0;
     }
 
     MatFileName.push_back(mapfile->Value());
