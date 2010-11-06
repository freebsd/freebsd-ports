http://github.com/pfenwick/finance-quote/commit/7de984bea80e9c5e00504ededba6897183bb8c45

--- t/bsero.t.orig        1970-01-01 08:00:00.000000000 +0800
+++ t/bsero.t    2010-02-13 18:25:22.000000000 +0800
@@ -0,0 +1,45 @@
+#!/usr/bin/perl -w
+use strict;
+use Test;
+use Data::Dumper;
+BEGIN {plan tests => 26};
+
+use Finance::Quote;
+
+# Test BSERO functions.
+
+my $q      = Finance::Quote->new();
+my @stocks = ("TLV", "BRD", "SNP");
+
+my %regexps = (
+	TLV  => qr/\bTLV\b/,
+	BRD => qr/\bBRD\b/,
+	SNP => qr/\bSNP\b/,
+);
+
+
+my %quotes = $q->fetch("bsero", @stocks);
+ok(%quotes);
+
+foreach my $stock (@stocks) {
+
+	my $name = $quotes{$stock, "name"};
+	print "#Testing $stock: $name\n";
+
+	my $regexp = $regexps{$stock};
+	ok($name =~ /$regexp/i);
+
+	ok($quotes{$stock, "exchange"} eq 'Bucharest Stock Exchange');
+	ok($quotes{$stock, "method"} eq 'bsero');
+
+	ok($quotes{$stock, "last"} > 0);
+	ok($quotes{$stock, "open"} =~ /^-?\d+\.\d+$/);
+	ok($quotes{$stock, "p_change"} =~ /^-?\d+\.\d+$/);
+	ok($quotes{$stock, "success"});
+	ok($quotes{$stock, "volume"} >= 0);
+}
+
+
+# Check that a bogus stock returns no-success.
+%quotes = $q->fetch("tsx", "BOGUS");
+ok(! $quotes{"BOGUS","success"});
