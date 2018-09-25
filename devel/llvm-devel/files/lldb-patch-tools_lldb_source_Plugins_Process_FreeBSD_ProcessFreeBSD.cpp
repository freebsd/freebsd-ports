--- tools/lldb/source/Plugins/Process/FreeBSD/ProcessFreeBSD.cpp.orig
+++ tools/lldb/source/Plugins/Process/FreeBSD/ProcessFreeBSD.cpp
@@ -335,7 +335,7 @@
     GetTarget().SetArchitecture(module_arch);
 
   // Initialize the target module list
-  GetTarget().SetExecutableModule(exe_module_sp, true);
+  GetTarget().SetExecutableModule(exe_module_sp, eLoadDependentsYes);
 
   SetSTDIOFileDescriptor(m_monitor->GetTerminalFD());
 
@@ -519,7 +519,7 @@
           executable_search_paths.GetSize() ? &executable_search_paths : NULL);
       if (!error.Success())
         return;
-      target->SetExecutableModule(exe_module_sp, true);
+      target->SetExecutableModule(exe_module_sp, eLoadDependentsYes);
     }
   }
 }
