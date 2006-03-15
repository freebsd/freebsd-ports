
$FreeBSD$

--- lib/hipe/cerl/cerl_hipeify.erl.orig
+++ lib/hipe/cerl/cerl_hipeify.erl
@@ -14,7 +14,7 @@
 %% Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 %% USA
 %%
-%% $Id$
+%% $Id: cerl_hipeify.erl,v 1.23 2006/03/10 13:40:37 tobiasl Exp $
 %%
 %% @author Richard Carlsson <richardc@csd.uu.se>
 %% @copyright 2000-2004 Richard Carlsson
@@ -361,6 +361,19 @@
 				cerl:atom_val(F),
 				length(As))
 		of
+	        {yes, ?PRIMOP_IS_RECORD} ->
+		    %% Needs additional testing
+		    [_, Tag, Arity] = As,
+		    case (cerl:is_c_atom(Tag) andalso 
+			  cerl:is_c_int(Arity)) of
+		        true ->
+			    %% The primop might need further handling
+			    N1 = cerl:c_atom(?PRIMOP_IS_RECORD),
+			    E1 = cerl:update_c_primop(E, N1, As),
+			    rewrite_primop(E1, N1, As, S);
+		        false ->
+			    cerl:update_c_call(E, M, F, As)
+		    end;
 		{yes, N} ->
 		    %% The primop might need further handling
 		    N1 = cerl:c_atom(N),
