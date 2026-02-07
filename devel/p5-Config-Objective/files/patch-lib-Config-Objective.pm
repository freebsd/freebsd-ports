--- ./lib/Config/Objective.pm.sav	Wed Apr  6 19:24:00 2005
+++ ./lib/Config/Objective.pm	Wed Apr  6 19:31:48 2005
@@ -91,17 +91,21 @@
 	$method = 'default'
 		if (!defined($method));
 
-	$retval = eval { $self->{'objs'}->{$obj}->$method(@args); };
-	if ($@)
+	#
+	# Trap and extend die and warn so we can tell the user where
+	# we were when the signals were generated.
+	#
+	if (@{$self->{'lexer_stack'}})
 	{
-		if (@{$self->{'lexer_stack'}})
-		{
-			$line = $self->{'lexer_stack'}->[-1]->line;
-			$msg = "$self->{'file_stack'}->[-1]:$line: ";
-		}
-		$msg .= "$obj";
-		die "$msg: $@";
+		$line = $self->{'lexer_stack'}->[-1]->line;
+		$msg = "$self->{'file_stack'}->[-1]: line $line: ";
 	}
+	$msg .= $obj;
+
+	local $SIG{__DIE__} = sub { die "$msg: $_[0]"; };
+	local $SIG{__WARN__} = sub { warn "$msg: $_[0]"; };
+
+	$retval = $self->{'objs'}->{$obj}->$method(@args);
 
 #	print "<== _call_obj_method(): returning '"
 #		. (defined($retval) ? $retval : 'undef') . "'\n";
