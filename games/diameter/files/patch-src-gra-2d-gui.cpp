--- src/gra/2d/gui.cpp.orig	Sat Jun 24 02:16:12 2006
+++ src/gra/2d/gui.cpp	Tue Sep 26 21:23:20 2006
@@ -3,11 +3,11 @@
 void DGUI::Init(Options in_option)
 {
 option=in_option;
-imageLoader = new gcn::OpenGLImageLoader();
+imageLoader = new gcn::OpenGLSDLImageLoader();
 hostImageLoader = new gcn::SDLImageLoader();
 // The OpenGL imageloader cant load images by itself, it needs
 // a host imageloader. So we give it an SDL imageloader.
-imageLoader->setHostImageLoader(hostImageLoader);
+//imageLoader->setHostImageLoader(hostImageLoader);
 gcn::Image::setImageLoader(imageLoader);
 graphics = new gcn::OpenGLGraphics();
 // We need to tell OpenGL graphics how big the screen is.
@@ -83,7 +83,7 @@
 b_ExitGame->setPosition(top->getWidth()/2-b_ExitGame->getWidth()/2, top->getHeight()/2+100);
 
 std::string temp_string = "texture/gui/logo.png";
-TempImage1 = new gcn::Image(PKGDATADIR+temp_string);
+TempImage1 = gcn::Image::load(PKGDATADIR+temp_string);
 diameter_icon = new gcn::Icon(TempImage1);
 diameter_icon->setPosition(top->getWidth()/2-diameter_icon->getWidth()/2, top->getHeight()/2-150);
 
