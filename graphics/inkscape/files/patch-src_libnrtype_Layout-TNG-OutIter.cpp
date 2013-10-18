--- src/libnrtype/Layout-TNG-OutIter.cpp.orig	2011-07-08 20:25:09.468790000 +0200
+++ src/libnrtype/Layout-TNG-OutIter.cpp	2013-10-17 13:12:08.000000000 +0200
@@ -197,7 +197,21 @@
 
 Layout::iterator Layout::sourceToIterator(void *source_cookie) const
 {
-    return sourceToIterator(source_cookie, Glib::ustring::const_iterator(std::string::const_iterator(NULL)));
+    // simply copied from above... what is an iterator to NULL?
+    unsigned source_index;
+    if (_characters.empty()) return end();
+    for (source_index = 0 ; source_index < _input_stream.size() ; source_index++)
+        if (_input_stream[source_index]->source_cookie == source_cookie) break;
+    if (source_index == _input_stream.size()) return end();
+
+    unsigned char_index = _sourceToCharacter(source_index);
+
+    if (_input_stream[source_index]->Type() != TEXT_SOURCE)
+        return iterator(this, char_index);
+
+    InputStreamTextSource const *text_source = static_cast<InputStreamTextSource const *>(_input_stream[source_index]);
+    //if (text_iterator <= text_source->text_begin) return iterator(this, char_index);
+       return iterator(this, char_index);
 }
 
 Geom::OptRect Layout::glyphBoundingBox(iterator const &it, double *rotation) const
@@ -506,18 +520,20 @@
     *source_cookie = stream_item->source_cookie;
     if (text_iterator && stream_item->Type() == TEXT_SOURCE) {
         InputStreamTextSource const *text_source = static_cast<InputStreamTextSource const *>(stream_item);
-        Glib::ustring::const_iterator text_iter_const = text_source->text_begin;
+        Glib::ustring::iterator text_iter = const_cast<Glib::ustring*>(text_source->text)->begin();
         unsigned char_index = it._char_index;
         unsigned original_input_source_index = _spans[_characters[char_index].in_span].in_input_stream_item;
         // confusing algorithm because the iterator goes forwards while the index goes backwards.
         // It's just that it's faster doing it that way
         while (char_index && _spans[_characters[char_index - 1].in_span].in_input_stream_item == original_input_source_index) {
-            ++text_iter_const;
+            ++text_iter;
             char_index--;
         }
-        text_source->text->begin().base() + (text_iter_const.base() - text_source->text->begin().base());
-        *text_iterator = Glib::ustring::iterator(std::string::iterator(const_cast<char*>(&*text_source->text->begin().base() + (text_iter_const.base() - text_source->text->begin().base()))));
-             // the caller owns the string, so they're going to want a non-const iterator
+        //text_source->text->begin().base() + (text_iter_const.base() - text_source->text->begin().base());
+        // FIXME C++11
+        //*text_iterator = Glib::ustring::iterator(std::string::iterator(const_cast<char*>(&*text_source->
+        // the caller owns the string, so they're going to want a non-const iterator
+        *text_iterator = text_iter;
     }
 }
 
