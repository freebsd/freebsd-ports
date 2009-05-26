--- sdk/wxpropgrid/src/propgrid.cpp.orig	2009-05-26 14:57:08.000000000 +0200
+++ sdk/wxpropgrid/src/propgrid.cpp	2009-05-26 15:03:13.000000000 +0200
@@ -1610,7 +1610,7 @@
 }
 
 // Slots of utility flags are NULL
-const int gs_propFlagToStringSize = 14;
+const unsigned int gs_propFlagToStringSize = 14;
 
 static const wxChar* gs_propFlagToString[gs_propFlagToStringSize] = {
     NULL,
@@ -7110,7 +7110,7 @@
 
     wxPropertyGridState* state = m_pState;
     int splitterHit;
-    int splitterHitOffset;
+    int splitterHitOffset = 0;
     int columnHit = state->HitTestH( x, &splitterHit, &splitterHitOffset );
 
     wxPGProperty* p = DoGetItemAtY(y);
@@ -7326,7 +7326,7 @@
 
     wxPropertyGridState* state = m_pState;
     int splitterHit;
-    int splitterHitOffset;
+    int splitterHitOffset = 0;
     int columnHit = state->HitTestH( x, &splitterHit, &splitterHitOffset );
     int splitterX = x - splitterHitOffset;
 
@@ -7957,7 +7957,7 @@
         return;
     }
 
-    int secondAction;
+    int secondAction = 0;
     int action = KeyEventToActions(event, &secondAction);
 
     if ( m_selected )
@@ -10509,7 +10509,7 @@
 
 wxPropertyGridHitTestResult wxPropertyGridState::HitTest( const wxPoint&pt ) const
 {
-    wxPropertyGridHitTestResult result;
+    wxPropertyGridHitTestResult result = {0};
     result.column = HitTestH( pt.x, &result.splitter, &result.splitterHitOffset );
     result.property = DoGetItemAtY( pt.y );
     return result;
