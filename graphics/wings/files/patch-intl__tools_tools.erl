--- intl_tools/tools.erl.orig	2016-09-23 14:29:04 UTC
+++ intl_tools/tools.erl
@@ -244,7 +244,7 @@ get_en_template_1([_|T]) ->
 %%%
 
 -define(STRINGS, wings_lang_transform_strings).
--define(FUNCTION_NAME, wings_lang_transform_function_name).
+-define(WINGS_FUNCTION_NAME, wings_lang_transform_function_name).
 -define(ERRORS, wings_lang_transform_errors).
 -define(FILENAME, wings_lang_transform_filename).
 
@@ -269,12 +269,12 @@ transform({attribute,_,file,{Filename,_}
     put(?FILENAME, Filename),
     Form;
 transform({function,L,Name,Arity,Cs}) ->
-    put(?FUNCTION_NAME, Name),
+    put(?WINGS_FUNCTION_NAME, Name),
     {function,L,Name,Arity,transform(Cs)};
 transform({call,L,{remote,_,{atom,_,wings_lang},{atom,_,str}}=Rem,
 	   [{tuple,_,[{atom,_,M}=Mod,Key]},
 	    {string,_,S}=Str]}) ->
-    FunName = get(?FUNCTION_NAME),
+    FunName = get(?WINGS_FUNCTION_NAME),
     K = literal_key(Key),
     add_string({{M,FunName,K},{S,L}}),
     {call,L,Rem,[{tuple,L,[Mod,{atom,L,FunName},Key]},Str]};
