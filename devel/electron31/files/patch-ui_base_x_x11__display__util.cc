--- ui/base/x/x11_display_util.cc.orig	2024-06-30 11:48:30 UTC
+++ ui/base/x/x11_display_util.cc
@@ -14,7 +14,6 @@
 
 #include "base/bits.h"
 #include "base/command_line.h"
-#include "base/containers/flat_map.h"
 #include "base/logging.h"
 #include "base/numerics/clamped_math.h"
 #include "base/ranges/algorithm.h"
@@ -28,7 +27,6 @@
 #include "ui/gfx/geometry/rect.h"
 #include "ui/gfx/geometry/rect_conversions.h"
 #include "ui/gfx/geometry/rect_f.h"
-#include "ui/gfx/switches.h"
 #include "ui/gfx/x/atom_cache.h"
 #include "ui/gfx/x/connection.h"
 #include "ui/gfx/x/randr.h"
@@ -43,89 +41,42 @@ constexpr const char kRandrEdidProperty[] = "EDID";
 
 constexpr const char kRandrEdidProperty[] = "EDID";
 
-std::map<x11::RandR::Output, size_t> GetMonitors(
-    const x11::Response<x11::RandR::GetMonitorsReply>& reply) {
-  std::map<x11::RandR::Output, size_t> output_to_monitor;
-  if (!reply) {
-    return output_to_monitor;
-  }
-  for (size_t monitor = 0; monitor < reply->monitors.size(); monitor++) {
-    for (x11::RandR::Output output : reply->monitors[monitor].outputs) {
-      output_to_monitor[output] = monitor;
+std::map<x11::RandR::Output, int> GetMonitors(
+    std::pair<uint32_t, uint32_t> version,
+    x11::RandR* randr,
+    x11::Window window) {
+  std::map<x11::RandR::Output, int> output_to_monitor;
+  if (version >= std::pair<uint32_t, uint32_t>{1, 5}) {
+    if (auto reply = randr->GetMonitors({window}).Sync()) {
+      for (size_t monitor = 0; monitor < reply->monitors.size(); monitor++) {
+        for (x11::RandR::Output output : reply->monitors[monitor].outputs) {
+          output_to_monitor[output] = monitor;
+        }
+      }
     }
   }
   return output_to_monitor;
 }
 
-x11::Future<x11::GetPropertyReply> GetWorkAreaFuture(
-    x11::Connection* connection) {
-  return connection->GetProperty({
-      .window = connection->default_root(),
-      .property = connection->GetAtom("_NET_WORKAREA"),
-      .long_length = 4,
-  });
-}
-
-gfx::Rect GetWorkAreaSync(x11::Future<x11::GetPropertyReply> future) {
-  auto response = future.Sync();
-  if (!response || response->format != 32 || response->value_len != 4) {
-    return gfx::Rect();
-  }
-  const uint32_t* value = response->value->cast_to<uint32_t>();
-  return gfx::Rect(value[0], value[1], value[2], value[3]);
-}
-
-x11::Future<x11::GetPropertyReply> GetIccProfileFuture(
-    x11::Connection* connection,
-    size_t monitor) {
-  std::string atom_name = monitor == 0
-                              ? "_ICC_PROFILE"
-                              : base::StringPrintf("_ICC_PROFILE_%zu", monitor);
-  auto future = connection->GetProperty({
-      .window = connection->default_root(),
-      .property = x11::GetAtom(atom_name.c_str()),
-      .long_length = std::numeric_limits<uint32_t>::max(),
-  });
-  future.IgnoreError();
-  return future;
-}
-
-gfx::ICCProfile GetIccProfileSync(x11::Future<x11::GetPropertyReply> future) {
-  auto response = future.Sync();
-  if (!response || !response->value_len) {
-    return gfx::ICCProfile();
-  }
-  return gfx::ICCProfile::FromData(response->value->bytes(),
-                                   response->value_len * response->format / 8u);
-}
-
-x11::Future<x11::RandR::GetOutputPropertyReply> GetEdidFuture(
-    x11::Connection* connection,
-    x11::RandR::Output output) {
-  auto future = connection->randr().GetOutputProperty({
-      .output = output,
-      .property = x11::GetAtom(kRandrEdidProperty),
-      .long_length = 128,
-  });
-  future.IgnoreError();
-  return future;
-}
-
 // Sets the work area on a list of displays.  The work area for each display
 // must already be initialized to the display bounds.  At most one display out
 // of |displays| will be affected.
 void ClipWorkArea(std::vector<display::Display>* displays,
-                  size_t primary_display_index,
-                  const gfx::Rect& net_workarea) {
-  if (net_workarea.IsEmpty()) {
+                  size_t primary_display_index) {
+  x11::Window x_root_window = ui::GetX11RootWindow();
+
+  std::vector<int32_t> value;
+  if (!x11::Connection::Get()->GetArrayProperty(
+          x_root_window, x11::GetAtom("_NET_WORKAREA"), &value) ||
+      value.size() < 4) {
     return;
   }
-
   auto get_work_area = [&](const display::Display& display) {
     float scale = display::Display::HasForceDeviceScaleFactor()
                       ? display::Display::GetForcedDeviceScaleFactor()
                       : display.device_scale_factor();
-    return gfx::ScaleToEnclosingRect(net_workarea, 1.0f / scale);
+    return gfx::ScaleToEnclosingRect(
+        gfx::Rect(value[0], value[1], value[2], value[3]), 1.0f / scale);
   };
 
   // If the work area entirely contains exactly one display, assume it's meant
@@ -207,9 +158,14 @@ int DefaultBitsPerComponent() {
   return visual.bits_per_rgb_value;
 }
 
-// Get the EDID data from the `output` and stores to `edid`.
-std::vector<uint8_t> GetEdidProperty(
-    x11::Response<x11::RandR::GetOutputPropertyReply> response) {
+// Get the EDID data from the |output| and stores to |edid|.
+std::vector<uint8_t> GetEDIDProperty(x11::RandR* randr,
+                                     x11::RandR::Output output) {
+  auto future = randr->GetOutputProperty(x11::RandR::GetOutputPropertyRequest{
+      .output = output,
+      .property = x11::GetAtom(kRandrEdidProperty),
+      .long_length = 128});
+  auto response = future.Sync();
   std::vector<uint8_t> edid;
   if (response && response->format == 8 && response->type != x11::Atom::None) {
     edid = std::move(response->data);
@@ -261,8 +217,7 @@ std::vector<display::Display> GetFallbackDisplayList(
 std::vector<display::Display> GetFallbackDisplayList(
     float scale,
     size_t* primary_display_index_out) {
-  auto* connection = x11::Connection::Get();
-  const auto& screen = connection->default_screen();
+  const auto& screen = x11::Connection::Get()->default_screen();
   gfx::Size physical_size(screen.width_in_millimeters,
                           screen.height_in_millimeters);
 
@@ -289,9 +244,7 @@ std::vector<display::Display> GetFallbackDisplayList(
   std::vector<display::Display> displays{gfx_display};
   *primary_display_index_out = 0;
 
-  ClipWorkArea(&displays, *primary_display_index_out,
-               GetWorkAreaSync(GetWorkAreaFuture(connection)));
-
+  ClipWorkArea(&displays, *primary_display_index_out);
   return displays;
 }
 
@@ -308,16 +261,7 @@ std::vector<display::Display> BuildDisplaysFromXRandRI
   auto x_root_window = ui::GetX11RootWindow();
   std::vector<display::Display> displays;
 
-  auto resources_future = randr.GetScreenResourcesCurrent({x_root_window});
-  auto output_primary_future = randr.GetOutputPrimary({x_root_window});
-  x11::Future<x11::RandR::GetMonitorsReply> monitors_future;
-  if (connection->randr_version() >= std::pair<uint32_t, uint32_t>{1, 5}) {
-    monitors_future = randr.GetMonitors(x_root_window);
-  }
-  auto work_area_future = GetWorkAreaFuture(connection);
-  connection->Flush();
-
-  auto resources = resources_future.Sync();
+  auto resources = randr.GetScreenResourcesCurrent({x_root_window}).Sync();
   if (!resources) {
     LOG(ERROR) << "XRandR returned no displays; falling back to root window";
     return GetFallbackDisplayList(primary_scale, primary_display_index_out);
@@ -326,65 +270,21 @@ std::vector<display::Display> BuildDisplaysFromXRandRI
   const int depth = connection->default_screen().root_depth;
   const int bits_per_component = DefaultBitsPerComponent();
 
-  auto output_primary = output_primary_future.Sync();
+  std::map<x11::RandR::Output, int> output_to_monitor =
+      GetMonitors(connection->randr_version(), &randr, x_root_window);
+  auto output_primary = randr.GetOutputPrimary({x_root_window}).Sync();
   if (!output_primary) {
     return GetFallbackDisplayList(primary_scale, primary_display_index_out);
   }
   x11::RandR::Output primary_display_id = output_primary->output;
 
-  const auto monitors_reply = monitors_future.Sync();
-  const auto output_to_monitor = GetMonitors(monitors_reply);
-  const size_t n_iccs =
-      monitors_reply ? std::max<size_t>(1, monitors_reply->monitors.size()) : 1;
-
   int explicit_primary_display_index = -1;
   int monitor_order_primary_display_index = -1;
 
-  std::vector<x11::Future<x11::RandR::GetCrtcInfoReply>> crtc_futures{};
-  crtc_futures.reserve(resources->crtcs.size());
-  for (auto crtc : resources->crtcs) {
-    crtc_futures.push_back(
-        randr.GetCrtcInfo({crtc, resources->config_timestamp}));
-  }
-  connection->Flush();
-
-  std::vector<x11::Future<x11::GetPropertyReply>> icc_futures{n_iccs};
-  if (!command_line->HasSwitch(switches::kHeadless)) {
-    for (size_t monitor = 0; monitor < n_iccs; ++monitor) {
-      icc_futures[monitor] = GetIccProfileFuture(connection, monitor);
-    }
-    connection->Flush();
-  }
-
-  std::vector<x11::Future<x11::RandR::GetOutputInfoReply>> output_futures{};
-  output_futures.reserve(resources->outputs.size());
-  for (auto output : resources->outputs) {
-    output_futures.push_back(
-        randr.GetOutputInfo({output, resources->config_timestamp}));
-  }
-  connection->Flush();
-
-  std::vector<x11::Future<x11::RandR::GetOutputPropertyReply>> edid_futures{};
-  edid_futures.reserve(resources->outputs.size());
-  for (auto output : resources->outputs) {
-    edid_futures.push_back(GetEdidFuture(connection, output));
-  }
-  connection->Flush();
-
-  base::flat_map<x11::RandR::Crtc, x11::RandR::GetCrtcInfoResponse> crtcs;
-  for (size_t i = 0; i < resources->crtcs.size(); ++i) {
-    crtcs.emplace(resources->crtcs[i], crtc_futures[i].Sync());
-  }
-
-  std::vector<gfx::ICCProfile> iccs;
-  iccs.reserve(n_iccs);
-  for (auto& future : icc_futures) {
-    iccs.push_back(GetIccProfileSync(std::move(future)));
-  }
-
   for (size_t i = 0; i < resources->outputs.size(); i++) {
     x11::RandR::Output output_id = resources->outputs[i];
-    auto output_info = output_futures[i].Sync();
+    auto output_info =
+        randr.GetOutputInfo({output_id, resources->config_timestamp}).Sync();
     if (!output_info) {
       continue;
     }
@@ -399,16 +299,15 @@ std::vector<display::Display> BuildDisplaysFromXRandRI
       continue;
     }
 
-    auto crtc_it = crtcs.find(output_info->crtc);
-    if (crtc_it == crtcs.end()) {
-      continue;
-    }
-    const auto& crtc = crtc_it->second;
+    auto crtc =
+        randr.GetCrtcInfo({output_info->crtc, resources->config_timestamp})
+            .Sync();
     if (!crtc) {
       continue;
     }
 
-    display::EdidParser edid_parser(GetEdidProperty(edid_futures[i].Sync()));
+    display::EdidParser edid_parser(
+        GetEDIDProperty(&randr, static_cast<x11::RandR::Output>(output_id)));
     auto output_32 = static_cast<uint32_t>(output_id);
     int64_t display_id =
         output_32 > 0xff ? 0 : edid_parser.GetIndexBasedDisplayId(output_32);
@@ -470,9 +369,8 @@ std::vector<display::Display> BuildDisplaysFromXRandRI
     }
 
     if (!display::HasForceDisplayColorProfile()) {
-      const size_t monitor =
-          monitor_iter == output_to_monitor.end() ? 0 : monitor_iter->second;
-      const auto& icc_profile = iccs[monitor < iccs.size() ? monitor : 0];
+      gfx::ICCProfile icc_profile = ui::GetICCProfileForMonitor(
+          monitor_iter == output_to_monitor.end() ? 0 : monitor_iter->second);
       gfx::ColorSpace color_space = icc_profile.GetPrimariesOnlyColorSpace();
 
       // Most folks do not have an ICC profile set up, but we still want to
@@ -517,24 +415,63 @@ std::vector<display::Display> BuildDisplaysFromXRandRI
     ConvertDisplayBoundsToDips(&displays, *primary_display_index_out);
   }
 
-  ClipWorkArea(&displays, *primary_display_index_out,
-               GetWorkAreaSync(std::move(work_area_future)));
+  ClipWorkArea(&displays, *primary_display_index_out);
   return displays;
 }
 
 base::TimeDelta GetPrimaryDisplayRefreshIntervalFromXrandr() {
   constexpr base::TimeDelta kDefaultInterval = base::Seconds(1. / 60);
-
-  size_t primary_display_index = 0;
-  auto displays = BuildDisplaysFromXRandRInfo(display::DisplayConfig(),
-                                              &primary_display_index);
-  CHECK_LT(primary_display_index, displays.size());
-
+  x11::RandR randr = x11::Connection::Get()->randr();
+  auto root = ui::GetX11RootWindow();
+  auto resources = randr.GetScreenResourcesCurrent({root}).Sync();
+  if (!resources) {
+    return kDefaultInterval;
+  }
   // TODO(crbug.com/41321728): It might make sense here to pick the output that
   // the window is on. On the other hand, if compositing is enabled, all drawing
   // might be synced to the primary output anyway. Needs investigation.
-  auto frequency = displays[primary_display_index].display_frequency();
-  return frequency > 0 ? base::Seconds(1. / frequency) : kDefaultInterval;
+  auto output_primary = randr.GetOutputPrimary({root}).Sync();
+  if (!output_primary) {
+    return kDefaultInterval;
+  }
+  x11::RandR::Output primary_output = output_primary->output;
+  bool disconnected_primary = false;
+  for (size_t i = 0; i < resources->outputs.size(); i++) {
+    if (!disconnected_primary && resources->outputs[i] != primary_output) {
+      continue;
+    }
+
+    auto output_info =
+        randr.GetOutputInfo({primary_output, resources->config_timestamp})
+            .Sync();
+    if (!output_info) {
+      continue;
+    }
+
+    if (output_info->connection != x11::RandR::RandRConnection::Connected) {
+      // If the primary monitor is disconnected, then start over and choose the
+      // first connected monitor instead.
+      if (!disconnected_primary) {
+        disconnected_primary = true;
+        i = -1;
+      }
+      continue;
+    }
+    auto crtc =
+        randr.GetCrtcInfo({output_info->crtc, resources->config_timestamp})
+            .Sync();
+    if (!crtc) {
+      continue;
+    }
+    float refresh_rate =
+        GetRefreshRateFromXRRModeInfo(resources->modes, crtc->mode);
+    if (refresh_rate == 0) {
+      continue;
+    }
+
+    return base::Seconds(1. / refresh_rate);
+  }
+  return kDefaultInterval;
 }
 
 int RangeDistance(int min1, int max1, int min2, int max2) {
