 Default to OpenGL, enables removing DirectX related source from the build, and
 makes the bgfx renderer initialisation work.

--- src/osd/modules/render/bgfx/shadermanager.cpp.orig	2023-11-09 05:21:49 UTC
+++ src/osd/modules/render/bgfx/shadermanager.cpp
@@ -85,7 +85,6 @@ std::string shader_manager::make_path_string(const osd
 	shader_path += PATH_SEPARATOR "shaders" PATH_SEPARATOR;
 	switch (bgfx::getRendererType())
 	{
-		case bgfx::RendererType::Noop:
 		case bgfx::RendererType::Direct3D9:
 			shader_path += "dx9";
 			break;
@@ -103,6 +102,7 @@ std::string shader_manager::make_path_string(const osd
 			shader_path += "metal";
 			break;
 
+		case bgfx::RendererType::Noop:
 		case bgfx::RendererType::OpenGL:
 			shader_path += "glsl";
 			break;
