--- src/source.cpp.orig	2023-08-03 07:43:31 UTC
+++ src/source.cpp
@@ -1193,57 +1193,61 @@ void Source::View::setup_format_style(bool is_generic_
         try {
           boost::property_tree::ptree pt;
           boost::property_tree::xml_parser::read_xml(stdout_stream, pt);
-          auto replacements_pt = pt.get_child("replacements", boost::property_tree::ptree());
-          for(auto it = replacements_pt.rbegin(); it != replacements_pt.rend(); ++it) {
-            if(it->first == "replacement") {
-              auto offset = it->second.get<size_t>("<xmlattr>.offset");
-              auto length = it->second.get<size_t>("<xmlattr>.length");
-              auto replacement_str = it->second.get<std::string>("");
+          for(auto it_root = pt.begin(); it_root != pt.end(); ++it_root) {
+            if(it_root->first == "replacements") {
+              for(auto it = it_root->second.rbegin(); it != it_root->second.rend(); ++it) {
+                if(it->first == "replacement") {
+                  auto offset = it->second.get<size_t>("<xmlattr>.offset");
+                  auto length = it->second.get<size_t>("<xmlattr>.length");
+                  auto replacement_str = it->second.get<std::string>("");
 
-              size_t bytes = 0;
-              for(size_t c = 0; c < bytes_in_lines.size(); ++c) {
-                auto previous_bytes = bytes;
-                bytes += bytes_in_lines[c];
-                if(offset < bytes || (c == bytes_in_lines.size() - 1 && offset == bytes)) {
-                  std::pair<size_t, size_t> line_index(c, offset - previous_bytes);
-                  auto start = get_buffer()->get_iter_at_line_index(line_index.first, line_index.second);
+                  size_t bytes = 0;
+                  for(size_t c = 0; c < bytes_in_lines.size(); ++c) {
+                    auto previous_bytes = bytes;
+                    bytes += bytes_in_lines[c];
+                    if(offset < bytes || (c == bytes_in_lines.size() - 1 && offset == bytes)) {
+                      std::pair<size_t, size_t> line_index(c, offset - previous_bytes);
+                      auto start = get_buffer()->get_iter_at_line_index(line_index.first, line_index.second);
 
-                  // Use left gravity insert to avoid moving cursor from end of line
-                  bool left_gravity_insert = false;
-                  if(get_buffer()->get_insert()->get_iter() == start) {
-                    auto iter = start;
-                    do {
-                      if(*iter != ' ' && *iter != '\t') {
-                        left_gravity_insert = iter.ends_line();
-                        break;
+                      // Use left gravity insert to avoid moving cursor from end of line
+                      bool left_gravity_insert = false;
+                      if(get_buffer()->get_insert()->get_iter() == start) {
+                        auto iter = start;
+                        do {
+                          if(*iter != ' ' && *iter != '\t') {
+                            left_gravity_insert = iter.ends_line();
+                            break;
+                          }
+                        } while(iter.forward_char());
                       }
-                    } while(iter.forward_char());
-                  }
 
-                  if(length > 0) {
-                    auto offset_end = offset + length;
-                    size_t bytes = 0;
-                    for(size_t c = 0; c < bytes_in_lines.size(); ++c) {
-                      auto previous_bytes = bytes;
-                      bytes += bytes_in_lines[c];
-                      if(offset_end < bytes || (c == bytes_in_lines.size() - 1 && offset_end == bytes)) {
-                        auto end = get_buffer()->get_iter_at_line_index(c, offset_end - previous_bytes);
-                        get_buffer()->erase(start, end);
-                        start = get_buffer()->get_iter_at_line_index(line_index.first, line_index.second);
-                        break;
+                      if(length > 0) {
+                        auto offset_end = offset + length;
+                        size_t bytes = 0;
+                        for(size_t c = 0; c < bytes_in_lines.size(); ++c) {
+                          auto previous_bytes = bytes;
+                          bytes += bytes_in_lines[c];
+                          if(offset_end < bytes || (c == bytes_in_lines.size() - 1 && offset_end == bytes)) {
+                            auto end = get_buffer()->get_iter_at_line_index(c, offset_end - previous_bytes);
+                            get_buffer()->erase(start, end);
+                            start = get_buffer()->get_iter_at_line_index(line_index.first, line_index.second);
+                            break;
+                          }
+                        }
                       }
+                      if(left_gravity_insert) {
+                        Mark mark(start);
+                        get_buffer()->insert(start, replacement_str);
+                        get_buffer()->place_cursor(mark->get_iter());
+                      }
+                      else
+                        get_buffer()->insert(start, replacement_str);
+                      break;
                     }
                   }
-                  if(left_gravity_insert) {
-                    Mark mark(start);
-                    get_buffer()->insert(start, replacement_str);
-                    get_buffer()->place_cursor(mark->get_iter());
-                  }
-                  else
-                    get_buffer()->insert(start, replacement_str);
-                  break;
                 }
               }
+              break;
             }
           }
         }
