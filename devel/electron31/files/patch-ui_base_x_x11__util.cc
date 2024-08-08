--- ui/base/x/x11_util.cc.orig	2024-06-18 21:44:02 UTC
+++ ui/base/x/x11_util.cc
@@ -703,4 +703,20 @@ gfx::ImageSkia GetNativeWindowIcon(intptr_t target_win
   return gfx::ImageSkia::CreateFrom1xBitmap(result);
 }
 
+gfx::ICCProfile GetICCProfileForMonitor(int monitor) {
+  gfx::ICCProfile icc_profile;
+  if (base::CommandLine::ForCurrentProcess()->HasSwitch(switches::kHeadless)) {
+    return icc_profile;
+  }
+  std::string atom_name = monitor == 0
+                              ? "_ICC_PROFILE"
+                              : base::StringPrintf("_ICC_PROFILE_%d", monitor);
+  scoped_refptr<base::RefCountedMemory> data;
+  if (GetRawBytesOfProperty(GetX11RootWindow(), x11::GetAtom(atom_name.c_str()),
+                            &data, nullptr)) {
+    icc_profile = gfx::ICCProfile::FromData(data->data(), data->size());
+  }
+  return icc_profile;
+}
+
 }  // namespace ui
