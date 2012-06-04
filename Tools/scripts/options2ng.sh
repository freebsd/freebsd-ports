#!/bin/sh
#
# $FreeBSD$
#
# This script makes a backup of the ports OPTIONS database and then converts
# all of the saved files to the new format.

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
