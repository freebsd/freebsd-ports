--- api/logic/minecraft/update/FMLLibrariesTask.h.orig	2018-06-03 04:17:36 UTC
+++ api/logic/minecraft/update/FMLLibrariesTask.h
@@ -1,6 +1,7 @@
 #pragma once
 #include "tasks/Task.h"
 #include "net/NetJob.h"
+#include "minecraft/VersionFilterData.h"
 class MinecraftInstance;
 
 class FMLLibrariesTask : public Task
