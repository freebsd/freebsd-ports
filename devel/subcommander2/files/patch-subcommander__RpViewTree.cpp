--- subcommander/RpViewTree.cpp.orig	2008-08-17 17:00:54.000000000 +0900
+++ subcommander/RpViewTree.cpp	2012-05-10 06:02:40.000000000 +0900
@@ -113,7 +113,7 @@
 
 
 RpViewTree::RpViewTree( const sc::String& root, RpViewState* state, ActionStorage* as, QWidget* parent )
-: super(parent), _state(state), _actions(as), _itemData(new RpViewEntryData())
+: super(parent), _itemData(new RpViewEntryData()), _state(state), _actions(as)
 {
   setTextElideMode(Qt::ElideMiddle);
   setAllColumnsShowFocus(true);
