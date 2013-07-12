diff --git src/modes/shop/shop_sell.cpp src/modes/shop/shop_sell.cpp
index 9fa3147..17537a2 100644
--- src/modes/shop/shop_sell.cpp
+++ src/modes/shop/shop_sell.cpp
@@ -295,10 +295,7 @@ void SellInterface::MakeActive()
 
 void SellInterface::TransactionNotification()
 {
-    _PopulateLists();
-
-    _current_category = _number_categories > 0 ? _number_categories - 1 : 0;
-    _view_mode = SHOP_VIEW_MODE_LIST;
+    Reinitialize();
 }
 
 
