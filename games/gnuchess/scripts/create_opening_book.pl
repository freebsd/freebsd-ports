#!/usr/bin/env perl
#
# Uses ./gnuchess to build 'book.bin' data from a 'book.pgn' input file
#

use IPC::Open2;

print "\nCreating opening book for gnuchess...\n";

unlink 'book.bin';
open2(\*OUT, \*IN, './gnuchess');

print IN "book add book.pgn\n";
while (<OUT>)
{
	print IN "quit\n" if /^all done/;
	print;
}

print "\nBook successfully created!\n"
