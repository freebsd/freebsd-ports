--- 3d-viewer/3d_rendering/legacy/3d_model.cpp.orig	2021-06-08 11:48:08 UTC
+++ 3d-viewer/3d_rendering/legacy/3d_model.cpp
@@ -488,7 +488,7 @@ void MODEL_3D::DrawBbox() const
                     reinterpret_cast<const void*>( offsetof( VERTEX, m_color ) ) );
 
     glDrawElements( GL_LINES, bbox_idx_count, m_bbox_index_buffer_type,
-                    reinterpret_cast<const void*>( NULL ) );
+                    reinterpret_cast<const void*>( 0 ) );
 }
 
 
