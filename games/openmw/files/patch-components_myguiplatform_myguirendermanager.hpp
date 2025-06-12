--- components/myguiplatform/myguirendermanager.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/myguiplatform/myguirendermanager.hpp
@@ -110,7 +110,7 @@ class RenderManager : public MyGUI::RenderManager, pub
     /** @see IRenderTarget::getInfo */
     const MyGUI::RenderTargetInfo& getInfo() const override { return mInfo; }
 
-    bool checkTexture(MyGUI::ITexture* _texture);
+    bool checkTexture(MyGUI::ITexture* _texture) override;
 
     void setViewSize(int width, int height) override;
 
