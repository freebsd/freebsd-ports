--- src/output-flex.cpp.orig	2022-01-24 15:04:03 UTC
+++ src/output-flex.cpp
@@ -636,7 +636,7 @@ void output_flex_t::write_column(
         }
     } else {
         throw std::runtime_error{
-            "Column type {} not implemented."_format(column.type())};
+            "Column type {} not implemented."_format(static_cast<uint8_t>(column.type()))};
     }
 
     lua_pop(lua_state(), 1);
