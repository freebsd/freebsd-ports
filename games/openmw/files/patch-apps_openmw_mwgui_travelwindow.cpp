--- apps/openmw/mwgui/travelwindow.cpp.orig	2023-08-08 09:23:20 UTC
+++ apps/openmw/mwgui/travelwindow.cpp
@@ -144,7 +144,7 @@ namespace MWGui
 
     void TravelWindow::onTravelButtonClick(MyGUI::Widget* _sender)
     {
-        std::istringstream iss(_sender->getUserString("price"));
+        std::istringstream iss(std::string{_sender->getUserString("price")});
         int price;
         iss >> price;
 
@@ -170,7 +170,7 @@ namespace MWGui
 
         MWBase::Environment::get().getWindowManager()->fadeScreenOut(1);
         ESM::Position pos = *_sender->getUserData<ESM::Position>();
-        std::string cellname = _sender->getUserString("Destination");
+        std::string cellname{_sender->getUserString("Destination")};
         bool interior = _sender->getUserString("interior") == "y";
         if (mPtr.getCell()->isExterior())
         {
