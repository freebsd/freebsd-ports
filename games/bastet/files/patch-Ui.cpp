Ui.cpp:174:18: error: non-constant-expression cannot be narrowed from type 'unsigned long' to 'int' in initializer list [-Wc++11-narrowing]
    return (Dot){maxlen+1,splits.size()};
                 ^~~~~~~~
Ui.cpp:174:18: note: insert an explicit cast to silence this issue
    return (Dot){maxlen+1,splits.size()};
                 ^~~~~~~~
                 static_cast<int>( )
Ui.cpp:174:27: error: non-constant-expression cannot be narrowed from type 'std::__1::vector<std::__1::basic_string<char>, std::__1::allocator<std::__1::basic_string<char> > >::size_type' (aka 'unsigned long') to 'int' in initializer list [-Wc++11-narrowing]
    return (Dot){maxlen+1,splits.size()};
                          ^~~~~~~~~~~~~
Ui.cpp:174:27: note: insert an explicit cast to silence this issue
    return (Dot){maxlen+1,splits.size()};
                          ^~~~~~~~~~~~~
                          static_cast<int>( )
Ui.cpp:236:12: error: non-constant-expression cannot be narrowed from type 'unsigned long' to 'int' in initializer list [-Wc++11-narrowing]
    Dot d={width+5,choices.size()};
           ^~~~~~~
Ui.cpp:236:12: note: insert an explicit cast to silence this issue
    Dot d={width+5,choices.size()};
           ^~~~~~~
           static_cast<int>( )
Ui.cpp:236:20: error: non-constant-expression cannot be narrowed from type 'std::__1::vector<std::__1::basic_string<char>, std::__1::allocator<std::__1::basic_string<char> > >::size_type' (aka 'unsigned long') to 'int' in initializer list [-Wc++11-narrowing]
    Dot d={width+5,choices.size()};
                   ^~~~~~~~~~~~~~
Ui.cpp:236:20: note: insert an explicit cast to silence this issue
    Dot d={width+5,choices.size()};
                   ^~~~~~~~~~~~~~
                   static_cast<int>( )

--- Ui.cpp.orig	2009-03-20 21:49:31 UTC
+++ Ui.cpp
@@ -171,7 +171,7 @@ namespace Bastet{
     BOOST_FOREACH(string &s, splits){
       maxlen=max(maxlen,s.size());
     }
-    return (Dot){maxlen+1,splits.size()};
+    return (Dot){(int)(maxlen+1),(int)splits.size()};
   }
 
   void Ui::MessageDialog(const std::string &message){
@@ -233,7 +233,7 @@ namespace Bastet{
       width=max(width,s.size());
     }
 
-    Dot d={width+5,choices.size()};
+    Dot d={(int)(width+5),(int)choices.size()};
     BorderedWindow w(d.y,d.x);
     wattrset((WINDOW *)w,COLOR_PAIR(20));
     for(size_t i=0;i<choices.size();++i){
