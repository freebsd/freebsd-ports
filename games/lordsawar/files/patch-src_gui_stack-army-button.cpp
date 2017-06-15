--- src/gui/stack-army-button.cpp.orig	2015-06-20 22:48:43 UTC
+++ src/gui/stack-army-button.cpp
@@ -146,7 +146,7 @@ void StackArmyButton::fill_army_button()
     {
       bool greyed_out = false;
       Stack *active_stack = p->getActivestack();
-      if (active_stack->getArmyById(d_army->getId()) == false)
+      if (!active_stack->getArmyById(d_army->getId()))
         greyed_out = true;
       army_image->property_pixbuf() =
         gc->getCircledArmyPic(p->getArmyset(), d_army->getTypeId(),
