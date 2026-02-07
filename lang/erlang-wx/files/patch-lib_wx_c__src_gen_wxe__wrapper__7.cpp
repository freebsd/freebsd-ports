--- lib/wx/c_src/gen/wxe_wrapper_7.cpp.orig	2022-10-15 17:50:46 UTC
+++ lib/wx/c_src/gen/wxe_wrapper_7.cpp
@@ -2339,7 +2339,7 @@ void wxToolBar_AddTool_4(WxeApp *app, wxeMemEnv *memen
     } else        Badarg("Options");
   };
   if(!This) throw wxe_badarg("This");
-  wxToolBarToolBase * Result = (wxToolBarToolBase*)This->AddTool(toolId,label,*bitmap,shortHelp,kind);
+  wxToolBarToolBase * Result = (wxToolBarToolBase*)This->AddTool(toolId,label,(wxBitmapBundle)*bitmap,shortHelp,kind);
   wxeReturn rt = wxeReturn(memenv, Ecmd.caller, true);
   rt.send(  rt.make_ref(app->getRef((void *)Result,memenv), "wx"));
 
