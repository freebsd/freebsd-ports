--- src/playlistgenerator/constraints/PlaylistFileSize.cpp.orig	2013-02-06 11:59:32.000000000 +0100
+++ src/playlistgenerator/constraints/PlaylistFileSize.cpp	2013-02-06 11:57:56.000000000 +0100
@@ -172,7 +172,7 @@
         case 2:
             return static_cast<quint64>( m_size ) * static_cast<quint64>( 1000000000 );
         case 3:
-            return static_cast<quint64>( m_size ) * static_cast<quint64>( 1000000000000 );
+            return static_cast<quint64>( m_size ) * static_cast<quint64>( 1000000000000LL );
         default:
             return static_cast<quint64>( m_size ) * static_cast<quint64>( 1 );
     }

