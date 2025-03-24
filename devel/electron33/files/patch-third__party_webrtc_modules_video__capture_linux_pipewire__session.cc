--- third_party/webrtc/modules/video_capture/linux/pipewire_session.cc.orig	2025-01-06 14:31:29 UTC
+++ third_party/webrtc/modules/video_capture/linux/pipewire_session.cc
@@ -85,7 +85,7 @@ PipeWireNode::PipeWireNode(PipeWireSession* session,
       .param = OnNodeParam,
   };
 
-  pw_node_add_listener(proxy_, &node_listener_, &node_events, this);
+  pw_node_add_listener(reinterpret_cast<pw_node*>(proxy_), &node_listener_, &node_events, this);
 }
 
 // static
@@ -117,7 +117,7 @@ void PipeWireNode::OnNodeInfo(void* data, const pw_nod
       uint32_t id = info->params[i].id;
       if (id == SPA_PARAM_EnumFormat &&
           info->params[i].flags & SPA_PARAM_INFO_READ) {
-        pw_node_enum_params(that->proxy_, 0, id, 0, UINT32_MAX, nullptr);
+        pw_node_enum_params(reinterpret_cast<pw_node*>(that->proxy_), 0, id, 0, UINT32_MAX, nullptr);
         break;
       }
     }
