--- ./src/3rdparty/javascriptcore/JavaScriptCore/interpreter/Interpreter.cpp.orig	2011-06-30 00:17:41.495446920 +0200
+++ ./src/3rdparty/javascriptcore/JavaScriptCore/interpreter/Interpreter.cpp	2011-06-30 00:19:46.885439368 +0200
@@ -2493,8 +2493,10 @@
             vPC += OPCODE_LENGTH(op_get_by_pname);
             NEXT_INSTRUCTION();
         }
+	{
         Identifier propertyName(callFrame, subscript.toString(callFrame));
         result = baseValue.get(callFrame, propertyName);
+	}
         CHECK_FOR_EXCEPTION();
         callFrame->r(dst) = result;
         vPC += OPCODE_LENGTH(op_get_by_pname);
