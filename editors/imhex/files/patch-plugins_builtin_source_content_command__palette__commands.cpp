--- plugins/builtin/source/content/command_palette_commands.cpp.orig	2023-04-08 16:49:33 UTC
+++ plugins/builtin/source/content/command_palette_commands.cpp
@@ -69,7 +69,7 @@ namespace hex::plugin::builtin {
                         if (auto combined = wolv::util::combineStrings(names, " -> "); hex::containsIgnoreCase(combined, input) && !combined.contains(ContentRegistry::Interface::impl::SeparatorValue) && !combined.contains(ContentRegistry::Interface::impl::SubMenuValue)) {
                             result.emplace_back(ContentRegistry::CommandPaletteCommands::impl::QueryResult {
                                 std::move(combined),
-                                [entry](const auto&) { entry.callback(); }
+                                [entry=entry](const auto&) { entry.callback(); }
                             });
                         }
                     }
