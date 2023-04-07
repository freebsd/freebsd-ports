--- tests/spec/ext_external_objects/vk.c.orig	2020-09-09 08:57:32 UTC
+++ tests/spec/ext_external_objects/vk.c
@@ -336,7 +336,7 @@ get_aspect_from_depth_format(VkFormat depth_format)
 	default:
 		break;
 	}
-	return VK_NULL_HANDLE;
+	return VK_IMAGE_ASPECT_NONE;
 }
 
 static VkPipelineStageFlags
