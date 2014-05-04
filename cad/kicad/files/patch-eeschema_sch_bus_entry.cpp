--- eeschema/sch_bus_entry.cpp.orig	2013-03-09 21:07:56.000000000 +0100
+++ eeschema/sch_bus_entry.cpp	2014-05-01 18:42:56.000000000 +0200
@@ -244,7 +244,7 @@
 }
 
 
-void SCH_BUS_ENTRY::GetConnectionPoints( vector< wxPoint >& aPoints ) const
+void SCH_BUS_ENTRY::GetConnectionPoints( std::vector< wxPoint >& aPoints ) const
 {
     aPoints.push_back( m_pos );
     aPoints.push_back( m_End() );
