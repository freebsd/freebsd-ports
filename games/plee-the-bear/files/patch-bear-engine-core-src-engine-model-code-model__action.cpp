--- bear-engine/core/src/engine/model/code/model_action.cpp.orig	2011-07-17 23:01:25.000000000 +0400
+++ bear-engine/core/src/engine/model/code/model_action.cpp	2013-09-14 03:46:40.203322514 +0400
@@ -396,7 +396,7 @@
 bear::engine::model_action::get_snapshot_const_iterator_at
 ( universe::time_type t ) const
 {
-  if ( claw::real_number<universe::time_type>(t) > get_duration() )
+  if ( (double)claw::real_number<universe::time_type>(t) > get_duration() )
     return m_snapshot.end();
   else if ( m_snapshot.empty() )
     return m_snapshot.end();
