http://github.com/pfenwick/finance-quote/commit/092599c712f19e7ddeb568340d42c816c9e1ed32

--- lib/Finance/Quote/Bourso.pm.orig	2009-10-06 01:39:57.000000000 +0800
+++ lib/Finance/Quote/Bourso.pm	2010-02-13 18:25:22.000000000 +0800
@@ -121,7 +121,7 @@
 		};
 
 		my $symbol = $symbolline[0]->as_text;
-		($symbol) = ($symbol=~m/(\w+)-/);
+		($symbol) = ($symbol=~m/(\w+) ?-/);
 		$info{$stocks,"symbol"}=$symbol;
 
 		# retrieve NAME
@@ -139,31 +139,71 @@
         # set method
         $info{$stocks,"method"} = "bourso" ;
 
+		#holds table data
+		my %tempinfo;
+
 		# retrieve other data
 		my $infoclass = ($tree->look_down('class','info1'))[0];
 		unless ($infoclass) {
-		  $info {$stocks,"success"} = 0;
-		  $info {$stocks,"errormsg"} = "$stocks retrieval not supported.";
-		  next ;
-		};
+		  my $opcvm = ($tree->look_down('id','opcvm_headerFund_0'))[0];
+		  unless ($opcvm) {
+			$info {$stocks,"success"} = 0;
+			$info {$stocks,"errormsg"} = "$stocks retrieval not supported.";
+			next ;
+		  }
+
+		  # the stock is a delayed OPCVM
+
+		  my $infoelem = ($tree->look_down('id','content-gauche'))[0];
+		  $infoelem = ($infoelem->look_down('class','TabContenu'))[0];
+
+		  my @rows = $infoelem->look_down('_tag','tr');
+		  foreach my $i (0..$#rows) {
+			my $row = $rows[$i];
+			unless($row->attr('class')) {
+			  next;
+			}
+
+			my @cells = $row->look_down('_tag','td');
+			my $keytext = ($cells[0])->as_text;
+			my $valuetext = ($cells[2])->as_text;
+
+			$tempinfo{$keytext} = $valuetext;
+		  }
+		}
+		else {
 
 		my $keys = ($infoclass->look_down('class','t01'))[0]; # this div contains all keys
 		my $data = ($infoclass->look_down('class','t03'))[0]; # this div contains all values
 		my @keys = $keys->look_down('_tag','li');
 		my @values = $data->look_down('_tag','li');
 
-		my %tempinfo; #holds table data
-
 		foreach my $i (0..$#keys) {
 		  my $keytext = ($keys[$i])->as_text;
 		  my $valuetext = ($values[$i])->as_text;
 		  $tempinfo{$keytext} = $valuetext;
 		}
 
+		}
+
 		foreach my $key (keys %tempinfo) {
 		  # print "$key -> $tempinfo{$key}\n";
 
 		ASSIGN:	for ( $key ) {
+			# OPCVM
+			/Valeur liquidative/ && do {
+			  my ($last, $currency) = ($tempinfo{$key} =~ m/(\d*.?\d*)\s*(\w*)/);
+			  $info{$stocks,"last"} = $last;
+			  $info{$stocks,"currency"} = $currency;
+			};
+			/Date/ && do {
+			  $info{$stocks,"date"} = $tempinfo{$key};
+			  $quoter->store_date(\%info, $stocks, {eurodate => $info{$stocks,"date"}});
+			};
+			/Variation Veille/ && do {
+			  $info{$stocks,"p_change"}=$tempinfo{$key}
+			};
+			# REGULAR STOCK
 			/Cours/ && do {
 			  my ($last, $currency) = ($tempinfo{$key} =~ m/(\d*.?\d*)\(c\)\s*(\w*)/);
 			  $info{$stocks,"last"} = $last;
