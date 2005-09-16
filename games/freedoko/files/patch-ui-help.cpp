--- ui/help.cpp.orig	Sun Aug  7 15:59:22 2005
+++ ui/help.cpp	Wed Sep 14 18:56:54 2005
@@ -49,7 +49,7 @@
    **
    **/
   string
-    Help::manual_directory()
+    manual_directory()
     {
 	vector<string> directory;
 
@@ -132,7 +132,7 @@
 	return ("http://free-doko.sourceforge.net/"
 		+ ::setting(Setting::HELP_DIRECTORY) + "/"
 		+ ::setting(Setting::LANGUAGE) + "/");
-    } // string Help::manual_directory()
+    } // string manual_directory()
 
   /**
    ** -> result
@@ -147,10 +147,10 @@
    **
    **/
   string
-    Help::operation_directory()
+    operation_directory()
     {
       return (manual_directory() + "operation/");
-    } // string Help::operation_directory()
+    } // string operation_directory()
 
   /**
    ** show the help page of the given location
@@ -165,7 +165,7 @@
    **
    **/
   void
-    Help::show(string const location)
+    show(string const location)
     {
 #ifndef WINDOWS
       ::system((::setting(Setting::BROWSER) + " " + location + " &").c_str());
@@ -174,7 +174,7 @@
 #endif
 
       return ;
-    } // void Help::show(string const location)
+    } // void show(string const location)
 
   /**
    ** show the manual help page of the given location
@@ -189,12 +189,12 @@
    **
    **/
   void
-    Help::show_manual(string const page)
+    show_manual(string const page)
     {
       show(manual_directory() + page + ".html");
 
       return ;
-    } // void Help::show_manual(string const page)
+    } // void show_manual(string const page)
 
   /**
    ** show the operation help page of the given location
@@ -209,12 +209,12 @@
    **
    **/
   void
-    Help::show_operation(string const page)
+    show_operation(string const page)
     {
       show(operation_directory() + page + ".html");
 
       return ;
-    } // void Help::show_operation(string const page)
+    } // void show_operation(string const page)
 
   /**
    ** shows the help for 'game_status'
@@ -231,10 +231,10 @@
    **
    **/
   void
-    Help::show(GameStatus const game_status)
+    show(GameStatus const game_status)
     {
       return ;
-    } // void Help::show(GameStatus const game_status)
+    } // void show(GameStatus const game_status)
 
   /**
    ** shows the help for the rule 'type'
@@ -251,10 +251,10 @@
    **
    **/
   void
-    Help::show(Rule::TypeBool const type)
+    show(Rule::TypeBool const type)
     {
       return ;
-    } // void Help::show(Rule::TypeBool const type)
+    } // void show(Rule::TypeBool const type)
 
   /**
    ** shows the help for the rule 'type'
@@ -271,10 +271,10 @@
    **
    **/
   void
-    Help::show(Rule::TypeUnsigned const type)
+    show(Rule::TypeUnsigned const type)
     {
       return ;
-    } // void Help::show(Rule::TypeUnsigned const type)
+    } // void show(Rule::TypeUnsigned const type)
 
   /**
    ** shows the help for the setting 'type'
@@ -291,10 +291,10 @@
    **
    **/
   void
-    Help::show(Setting::TypeBool const type)
+    show(Setting::TypeBool const type)
     {
       return ;
-    } // void Help::show(Setting::TypeBool const type)
+    } // void show(Setting::TypeBool const type)
 
   /**
    ** shows the help for the setting 'type'
@@ -311,10 +311,10 @@
    **
    **/
   void
-    Help::show(Setting::TypeUnsigned const type)
+    show(Setting::TypeUnsigned const type)
     {
       return ;
-    } // void Help::show(Setting::TypeUnsigned const type)
+    } // void show(Setting::TypeUnsigned const type)
 
   /**
    ** shows the help for the setting 'type'
@@ -331,10 +331,10 @@
    **
    **/
   void
-    Help::show(Setting::TypeString const type)
+    show(Setting::TypeString const type)
     {
       return ;
-    } // void Help::show(Setting::TypeString const type)
+    } // void show(Setting::TypeString const type)
 
   /**
    ** shows the help for the setting 'type'
@@ -351,9 +351,9 @@
    **
    **/
   void
-    Help::show(Setting::TypeCardsOrder const type)
+    show(Setting::TypeCardsOrder const type)
     {
       return ;
-    } // void Help::show(Setting::TypeCardsOrder const type)
+    } // void show(Setting::TypeCardsOrder const type)
 
 } // namespace Help
