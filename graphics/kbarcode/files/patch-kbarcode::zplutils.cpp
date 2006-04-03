--- kbarcode/zplutils.cpp.orig	Mon Mar 21 00:31:21 2005
+++ kbarcode/zplutils.cpp	Thu Mar 16 12:27:36 2006
@@ -256,7 +256,7 @@
     ipl += field( "<ESC>E3<CAN>" );  // choose format number 3
 
     for( unsigned int i = 0; i < m_values.count(); i++ )
-        ipl += field( m_values[i] + ( i != m_values.count() - 1 ? "<CR>" : QString::null ) );
+        ipl += field( m_values[i] + ( i != m_values.count() - 1 ? QString("<CR>") : QString::null ) );
 
     // end actual data
     ipl += field( "<ETB>" );
