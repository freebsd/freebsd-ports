 Default to OpenGL, enables removing DirectX related source from the build, and
 makes the bgfx renderer initialisation work.

--- src/osd/modules/render/bgfx/shadermanager.cpp.orig	2026-07-29 15:13:25 UTC
+++ src/osd/modules/render/bgfx/shadermanager.cpp
@@ -95,6 +95,5 @@ std::string shader_manager::make_path_string(const osd
 	switch (bgfx::getRendererType())
 	{
-		case bgfx::RendererType::Noop:
 		case bgfx::RendererType::Direct3D9:
 			shader_path += "dx9";
 			break;
@@ -115,3 +114,4 @@ std::string shader_manager::make_path_string(const osd
+		case bgfx::RendererType::Noop:
 		case bgfx::RendererType::OpenGL:
 			shader_path += "glsl";
 			break;
