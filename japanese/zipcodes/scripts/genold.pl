while (<>) {
	s/"//g;
	split(/,/, $_);
	$_[1] =~ s/[ \t]//g;
	$_[8] = '' if ($_[8] eq '以下に掲載がない場合');
	$zipstr = $_[6] . ' ' . $_[7] . ' ' . $_[8];	# uniq
	$zipstr =~ s/[ \t]+$//;
	$zip{$zipstr} = $_[1];
}

print "# Zip code:location\n";
print "# 3 to 5 digits zipcode for japan, used until jan98.\n";
foreach $i (sort {$zip{$a} cmp $zip{$b}} keys %zip) {
	next if ($i eq '');
	print $zip{$i} . ':' . $i . "\n";
}
