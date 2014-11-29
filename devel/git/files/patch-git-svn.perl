--- git-svn.perl.orig	2014-11-16 02:01:16 UTC
+++ git-svn.perl
@@ -115,7 +115,7 @@ my ($_stdin, $_help, $_edit,
 	$_before, $_after,
 	$_merge, $_strategy, $_preserve_merges, $_dry_run, $_parents, $_local,
 	$_prefix, $_no_checkout, $_url, $_verbose,
-	$_commit_url, $_tag, $_merge_info, $_interactive);
+	$_commit_url, $_tag, $_merge_info, $_interactive, $_set_svn_props);
 
 # This is a refactoring artifact so Git::SVN can get at this git-svn switch.
 sub opt_prefix { return $_prefix || '' }
@@ -193,6 +193,7 @@ my %cmd = (
 			  'dry-run|n' => \$_dry_run,
 			  'fetch-all|all' => \$_fetch_all,
 			  'commit-url=s' => \$_commit_url,
+			  'set-svn-props=s' => \$_set_svn_props,
 			  'revision|r=i' => \$_revision,
 			  'no-rebase' => \$_no_rebase,
 			  'mergeinfo=s' => \$_merge_info,
@@ -228,6 +229,9 @@ my %cmd = (
         'propget' => [ \&cmd_propget,
 		       'Print the value of a property on a file or directory',
 		       { 'revision|r=i' => \$_revision } ],
+        'propset' => [ \&cmd_propset,
+		       'Set the value of a property on a file or directory - will be set on commit',
+		       {} ],
         'proplist' => [ \&cmd_proplist,
 		       'List all properties of a file or directory',
 		       { 'revision|r=i' => \$_revision } ],
@@ -1370,6 +1374,50 @@ sub cmd_propget {
 	print $props->{$prop} . "\n";
 }
 
+# cmd_propset (PROPNAME, PROPVAL, PATH)
+# ------------------------
+# Adjust the SVN property PROPNAME to PROPVAL for PATH.
+sub cmd_propset {
+	my ($propname, $propval, $path) = @_;
+	$path = '.' if not defined $path;
+	$path = $cmd_dir_prefix . $path;
+	usage(1) if not defined $propname;
+	usage(1) if not defined $propval;
+	my $file = basename($path);
+	my $dn = dirname($path);
+	# diff has check_attr locally, so just call direct 
+	#my $current_properties = check_attr( "svn-properties", $path );
+	my $current_properties = Git::SVN::Editor::check_attr( "svn-properties", $path );
+	my $new_properties = "";
+	if ($current_properties eq "unset" || $current_properties eq "" || $current_properties eq "set") {
+		$new_properties = "$propname=$propval";
+	} else {
+		# TODO: handle combining properties better
+		my @props = split(/;/, $current_properties);
+		my $replaced_prop = 0;
+		foreach my $prop (@props) {
+			# Parse 'name=value' syntax and set the property.
+			if ($prop =~ /([^=]+)=(.*)/) {
+				my ($n,$v) = ($1,$2);
+				if ($n eq $propname)
+				{
+					$v = $propval;
+					$replaced_prop = 1;
+				}
+				if ($new_properties eq "") { $new_properties="$n=$v"; }
+				else { $new_properties="$new_properties;$n=$v"; }
+			}
+		}
+		if ($replaced_prop eq 0) {
+			$new_properties = "$new_properties;$propname=$propval";
+		}
+	}
+	my $attrfile = "$dn/.gitattributes";
+	open my $attrfh, '>>', $attrfile or die "Can't open $attrfile: $!\n";
+	# TODO: don't simply append here if $file already has svn-properties
+	print $attrfh "$file svn-properties=$new_properties\n";
+}
+
 # cmd_proplist (PATH)
 # -------------------
 # Print the list of SVN properties for PATH.
