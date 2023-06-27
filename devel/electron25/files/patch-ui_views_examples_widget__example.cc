--- ui/views/examples/widget_example.cc.orig	2023-02-01 18:43:52 UTC
+++ ui/views/examples/widget_example.cc
@@ -49,7 +49,7 @@ void WidgetExample::CreateExampleView(View* container)
   modal_button->SetCallback(
       base::BindRepeating(&WidgetExample::CreateDialogWidget,
                           base::Unretained(this), modal_button, true));
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   LabelButton* control_button = BuildButton(
       container, GetStringUTF16(IDS_WIDGET_CHILD_WIDGET_BUTTON_LABEL));
