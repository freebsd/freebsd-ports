#!/bin/sh
#
# $FreeBSD$
#
# This script makes a backup of the ports OPTIONS database and then converts
# all of the saved files to the new format.

usage()
{
	<<EOF cat
Usage:

$0 -p

Converts the ports OPTIONS database from WITH_/WITHOUT_ format to
OPTIONS_FILE_SET format.  A backup tar archive is created and left in /tmp.

$0 -f [filename]

Converts filename (in WITH_/WITHOUT_ format, for example make.conf) into
OPTIONS_SET format.

XXX The output must be checked; the script attempts to avoid changes that
make no sense, but some may slip through.  To avoid nonsensical conversions
(such as WITH_*_VER) only WITH_ variables that are set to "true" or "yes"
(case-insensitive, with or without quotes) will be converted.

EOF
}

args=$(getopt pf: $*)
if [ $? -ne 0 ]; then
	usage;
	exit 2
fi

set -- $args

case "$1" in
-p)
	PORT_DBDIR=$(make -C /usr/ports/shells/bash -V PORT_DBDIR)

	tar cfz $(mktemp /tmp/optionsbackup.tar.gz.XXX) $PORT_DBDIR

	for optionsfile in $PORT_DBDIR/*/options
	do  if grep -q ^WITH $optionsfile ; then
		options_read=
		echo "Converting $optionsfile"
		tmpfile=$(mktemp /tmp/optionsconvert.XXXXXXX) || exit 1
		grep '^[#_]' $optionsfile > $tmpfile
		for option in $(sed -ne 's/^WITH_\([^=]*\)=true/\1/p' < $optionsfile)
		do  echo "OPTIONS_FILE_SET+=$option" >> $tmpfile
		    options_read="${options_read} $option"
		done
		for option in $(sed -ne 's/^WITHOUT_\([^=]*\)=true/\1/p' < $optionsfile)
		do  echo "OPTIONS_FILE_UNSET+=$option" >> $tmpfile
		    options_read="${options_read} $option"
		done
		echo "_FILE_COMPLETE_OPTIONS_LIST=$options_read" >> $tmpfile
		mv $tmpfile $optionsfile
		chmod 644 $optionsfile
	    fi
	done
	;;
-f)
	filename=$2
	if [ ! -f $filename ]
	then echo $filename does not exist!
	     exit 2
	fi

	tmpfile=$(mktemp /tmp/makeconfconvert.XXXXXXX) || exit 1

	IFS='
'
	for line in $(cat $filename)
	do  if $(echo $line | grep -Eq '(PKGNG|DEBUG)')
	    then echo $line >> $tmpfile
	    else echo $line | sed -E \
		-e 's,^WITH_([^=]*)=[	 ]*.?[TtYy][RrEe][UuSs][Ee]?.?,OPTIONS_SET+=	\1,' \
		-e 's,^WITHOUT_([^=]*)=[ 	]*.?[TtYy][RrEe][UuSs][Ee]?.?,OPTIONS_UNSET+=	\1,' \
	      >> $tmpfile
	    fi
	done

	diff -yW 80 $filename $tmpfile

	<<EOF cat

The results are stored in $tmpfile; please check it for
sanity and copy it back over the original file (remember to keep a backup
copy of the original file!)

EOF
	
	;;
*)
	usage
	;;
esac
