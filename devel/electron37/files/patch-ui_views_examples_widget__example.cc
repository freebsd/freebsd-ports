--- ui/views/examples/widget_example.cc.orig	2025-04-22 20:15:27 UTC
+++ ui/views/examples/widget_example.cc
@@ -51,7 +51,7 @@ void WidgetExample::CreateExampleView(View* container)
   modal_button->SetCallback(
       base::BindRepeating(&WidgetExample::CreateDialogWidget,
                           base::Unretained(this), modal_button, true));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   LabelButton* control_button = BuildButton(
       container, GetStringUTF16(IDS_WIDGET_CHILD_WIDGET_BUTTON_LABEL));
