--- guitest/guitest.cpp.orig	2005-04-07 05:53:51 UTC
+++ guitest/guitest.cpp
@@ -96,19 +96,19 @@ class MyConsole : public KrConsole
 		switch ( event.type )
 		{
 			case KrWidgetEvent::ACTIVATED:
-				sprintf( buf, "ACTIVATED %s source=0x%x\n", source->WidgetType(), (unsigned)source );
+				sprintf( buf, "ACTIVATED %s source=0x%x\n", source->WidgetType(), (uintptr_t)source );
 				break;
 
 			case KrWidgetEvent::DEACTIVATED:
-				sprintf( buf, "DEACTIVATED %s source=0x%x\n", source->WidgetType(), (unsigned)source );
+				sprintf( buf, "DEACTIVATED %s source=0x%x\n", source->WidgetType(), (uintptr_t)source );
 				break;
 
 			case KrWidgetEvent::COMMAND:
-				sprintf( buf, "COMMAND %s source=0x%x command=%s arg=%s\n", source->WidgetType(), (unsigned)source, event.command.command, event.command.arg );
+				sprintf( buf, "COMMAND %s source=0x%x command=%s arg=%s\n", source->WidgetType(), (uintptr_t)source, event.command.command, event.command.arg );
 				break;
 
 			case KrWidgetEvent::SELECTION:
-				sprintf( buf, "SELECTION %s source=0x%x id=%d text=%s\n", source->WidgetType(), (unsigned)source, event.selection.index, event.selection.text ? event.selection.text : "(null)" );
+				sprintf( buf, "SELECTION %s source=0x%x id=%d text=%s\n", source->WidgetType(), (uintptr_t)source, event.selection.index, event.selection.text ? event.selection.text : "(null)" );
 				break;
 				
 			default:
