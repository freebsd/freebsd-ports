
$FreeBSD$

--- lib/elixir/src/elixir.erl.orig
+++ lib/elixir/src/elixir.erl
@@ -29,9 +29,9 @@
     end,
 
   ok = io:setopts(standard_io, Opts),
-  %% Must use undocument {unicode, true} to set unicode on standard_error, more
+  %% Must use {encoding,unicode} to set unicode on standard_error, more
   %% info: http://erlang.org/pipermail/erlang-bugs/2014-April/004310.html
-  ok = io:setopts(standard_error, [{unicode,true}]),
+  ok = io:setopts(standard_error, [{encoding,unicode}]),
   case file:native_name_encoding() of
     latin1 ->
       io:format(standard_error,
