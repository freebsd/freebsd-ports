--- source/base/image/image.cpp.orig	2011-01-22 06:31:21.000000000 +0100
+++ source/base/image/image.cpp	2011-03-08 12:37:06.000000000 +0100
@@ -2886,7 +2886,7 @@
 			meta[0] = sizeof(pixel_type);
 			meta[1] = m_Width;
 			meta[2] = m_Height;
-			if (lseek64(m_File, pos, SEEK_SET) != pos)
+			if (lseek(m_File, pos, SEEK_SET) != pos)
 					throw POV_EXCEPTION(kFileDataErr, "Intermediate image storage backing file write/seek failed at creation.");
 			if (write(m_File, &meta[0], (int) sizeof(size_type)*3) != (sizeof(size_type)*3))
 					throw POV_EXCEPTION(kFileDataErr, "Intermediate image storage backing file write failed at creation.");
@@ -3057,7 +3057,7 @@
 #endif
 				pos = block * sizeof(pixel_type) * m_Blocksize;
 				int chunk = sizeof(pixel_type) * m_Blocksize;
-				if (lseek64(m_File, pos, SEEK_SET) != pos)
+				if (lseek(m_File, pos, SEEK_SET) != pos)
 					throw POV_EXCEPTION(kFileDataErr, "Intermediate image storage backing file read/seek failed.");
 				int bytes = read(m_File, &m_Buffer[0], chunk);
 				if (bytes != (sizeof(pixel_type) * m_Blocksize))
@@ -3080,7 +3080,7 @@
 
 			if (m_Dirty) {
 				pos = m_CurrentBlock * sizeof(pixel_type) * m_Blocksize;
-				if (lseek64(m_File, pos, SEEK_SET) != pos)
+				if (lseek(m_File, pos, SEEK_SET) != pos)
 					throw POV_EXCEPTION(kFileDataErr, "Intermediate image storage backing file write/seek failed.");
 				if (write(m_File, &m_Buffer[0], (int) sizeof(pixel_type) * m_Blocksize) != (sizeof(pixel_type) * m_Blocksize))
 					throw POV_EXCEPTION(kFileDataErr, "Intermediate image storage backing file write failed.");
