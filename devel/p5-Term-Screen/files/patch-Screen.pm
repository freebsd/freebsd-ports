--- Screen.pm.orig	Tue Oct 30 16:47:00 2001
+++ Screen.pm	Thu Jan 17 19:25:32 2002
@@ -8,7 +8,7 @@
 
 =head1 NAME
 
-Term::Screen
+Term::Screen - A Simple all perl Term::Cap based screen positioning module
 
 =head1 SYNOPSIS
 
@@ -419,7 +419,7 @@
             }
           else		# buffer up the received chars
             {
-              $this->{IN} = reverse($partial_fn_str) . $this->{IN};
+              $this->{IN} = &reverse($partial_fn_str) . $this->{IN};
               $c = chop($this->{IN});
               $this->puts($c) if ($this->{ECHO} && ($c ne "\e"));
             }
@@ -454,7 +454,7 @@
 sub stuff_input 
 { 
  my ($this, $str) = @_;
- $this->{IN} = reverse($str) . $this->{IN}; 
+ $this->{IN} = &reverse($str) . $this->{IN}; 
  $this; 
 }
 
