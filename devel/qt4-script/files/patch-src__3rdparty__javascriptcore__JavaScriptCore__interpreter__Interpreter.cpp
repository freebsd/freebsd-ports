--- ./src/3rdparty/javascriptcore/JavaScriptCore/interpreter/Interpreter.cpp.orig	2011-06-30 00:43:03.155579428 +0200
+++ ./src/3rdparty/javascriptcore/JavaScriptCore/interpreter/Interpreter.cpp	2011-06-30 00:43:34.275444696 +0200
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
