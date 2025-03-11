--- media/Ac3d.cc.orig	2014-04-02 21:55:37 UTC
+++ media/Ac3d.cc
@@ -791,7 +791,7 @@ Ac3d_Object::Ac3d_Object (std::string type, double sca
 	  }
 	buffer [length] = '\0';
 	m_data = std::string (buffer);
-	delete buffer;
+	delete[] buffer;
   }
 
   void 
@@ -808,11 +808,11 @@ Ac3d_Object::Ac3d_Object (std::string type, double sca
 	  }
 
 	std::for_each (m_surfaces.begin (), m_surfaces.end (), 
-				   std::mem_fun (&Ac3d_Surface::build));
+				   std::mem_fn (&Ac3d_Surface::build));
 
 	glDisable (GL_TEXTURE_2D);
 	std::for_each (m_kids.begin (), m_kids.end (), 
-				   std::mem_fun (&Ac3d_Object::build));
+				   std::mem_fn (&Ac3d_Object::build));
 	glEnable (GL_TEXTURE_2D);
   }
 
@@ -892,7 +892,7 @@ Ac3d_Object::Ac3d_Object (std::string type, double sca
 	m_rotation (rotation)
   {
 	std::ifstream is (m_file.c_str ());
-	if (is == 0)
+	if (!is)
 	  {
 		throw No_File (m_file);
 	  }
@@ -1215,7 +1215,7 @@ Ac3d_Object::Ac3d_Object (std::string type, double sca
 	glNewList (id, GL_COMPILE);
 
 	std::for_each (m_objects.begin (), m_objects.end (), 
-				   std::mem_fun (&Ac3d_Object::build));
+				   std::mem_fn (&Ac3d_Object::build));
 
 	glEndList ();
 
