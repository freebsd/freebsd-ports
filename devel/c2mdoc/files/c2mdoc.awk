#!/usr/bin/awk -f
#
# c2mdoc.awk -- Takes tabulated output from cproto(1) and turns it into
#               mdoc(7) markup.
#
# $FreeBSD$
#
BEGIN { FS="\t" }
{
	printf ".Ft %s\n", $1 ;
	printf ".Fn %s", $2 ;
	for (i = 4; i < NF; i++)
		printf " \"%s\"", $i 
	printf "\n" ;
}
