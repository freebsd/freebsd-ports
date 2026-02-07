--- gmusicbrowser_list.pm.orig	2019-02-23 05:30:39 UTC
+++ gmusicbrowser_list.pm
@@ -7998,7 +7998,7 @@ sub Make
 			unless ($notnow)
 			{	#warn "$key ---found in ($code,@deps)\n";
 				if (ref $code)
-				{	my ($func,my @keys)=@$code; #warn " -> ($func, @keys)\n";
+				{	my ($func,@keys)=@$code; #warn " -> ($func, @keys)\n";
 					my $out=join ',',map "'$_'", @keys;
 					my $in= join ',',map "'$_'", @deps; $in=~s#\?##g;
 					$out= @keys>1 ? "\@var{$out}" : "\$var{$out}";
