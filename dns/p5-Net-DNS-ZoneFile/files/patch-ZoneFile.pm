$FreeBSD$

--- ZoneFile.pm.orig	Tue Jun 11 20:34:27 2002
+++ ZoneFile.pm	Tue Jun 11 20:35:23 2002
@@ -129,23 +129,23 @@
 	elsif ($text =~		# SOA
 	       s/
 	       \A(|\*|\s*@|\.|([-\w\d]+(\.[-\w\d]+)*\.?))
-	       \s+ ((IN|HESIOD|CHAOS) \s+)?
+	       \s+ (?:([\d]+)\s+)? ((IN|HESIOD|CHAOS) \s+)?
 	       (SOA) \s+ ([-\w\d]+(\.[-\w\d]+)*\.) 
 	       \s+ ([-\w\d]+(\.[-\w\d]+)*\.) \s* \(
 	       \s* (\d+) \s+ (\d+) \s+ (\d+) \s+ (\d+) \s+ (\d+) \s+ \) \s*$
 	       //mxi)
 	{
 	    my $name	= $1;
-	    my $class	= $5 || 'IN';
-	    my $type	= $6;
-	    my $host	= $7;
-	    my $admin	= $9;
-	    my $d1	= $11;
-	    my $d2	= $12;
-	    my $d3	= $13;
-	    my $d4	= $14;
-	    my $d5	= $15;
-	    my $ttl	= $d5;
+	    my $class	= $6 || 'IN';
+	    my $type	= $7;
+	    my $host	= $8;
+	    my $admin	= $10;
+	    my $d1	= $12;
+	    my $d2	= $13;
+	    my $d3	= $14;
+	    my $d4	= $15;
+	    my $d5	= $16;
+	    my $ttl	= $4 || $d5;
 
 	    $SoaTTL = $ttl;
 
