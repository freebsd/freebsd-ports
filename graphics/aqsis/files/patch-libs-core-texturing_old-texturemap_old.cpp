--- libs/core/texturing_old/texturemap_old.cpp.orig	2012-02-20 18:39:35.000000000 +0300
+++ libs/core/texturing_old/texturemap_old.cpp	2012-02-20 18:39:50.000000000 +0300
@@ -578,7 +578,7 @@
 		}
 
 		// Now open it as a tiff file.
-		m_pImage = TIFFOpen( imagePath.file_string().c_str(), "r" );
+		m_pImage = TIFFOpen( imagePath.string().c_str(), "r" );
 	}
 
 	if ( m_pImage )
@@ -1090,7 +1090,7 @@
 		Aqsis::log() << error << "Cannot open texture file \"" << m_strName.c_str() << "\"" << std::endl;
 		return ;
 	}
-	m_pImage = TIFFOpen(imagePath.file_string().c_str(), "r" );
+	m_pImage = TIFFOpen(imagePath.string().c_str(), "r" );
 
 	if ( m_pImage )
 	{
