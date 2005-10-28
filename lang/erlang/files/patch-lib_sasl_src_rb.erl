
$FreeBSD$

--- lib/sasl/src/rb.erl.orig
+++ lib/sasl/src/rb.erl
@@ -414,7 +414,7 @@
 		    Ref = make_ref(),
 		    case (catch {Ref,binary_to_term(Bin)}) of
 			{'EXIT',_} ->
-			    {error, "Inclomplete erlang term in log"};
+			    {error, "Incomplete erlang term in log"};
 			{Ref,Term} ->
 			    {ok, Term}
 		    end
