#!/bin/sh
#
# pgp.config.l10n.sh  - modify PGP configuration file to localization.
#
#  Copyright(C) 1997  Hironori Ikura <hikura@tcc.co.jp>
#
# usage: pgp.config.l10n.sh <srcdir> <lang> <charset>
# ex. pgp.config.l10n.sh /usr/ports/japanese/pgp/work ja noconv
#

if [ $# -ne 3 ]; then
	echo "usage: $0 <srcdir> <lang> <charset>" 1>&2
	echo "  ex. $0 /usr/ports/japanese/pgp/work ja noconv" 1>&2
	exit 1
fi

wrkdir=$1
lang=$2
charset=$3
config=$wrkdir/config.txt

if [ ! -f "$config" ]; then
	echo "No original config.txt is found." 1>&2
	echo "Abort processing." 1>&2
	exit 1
fi

mv $config $config.bak

sed -e 's/^[Ll]anguage *= *[a-z][a-z]$/Language = '$lang'/' \
    -e 's/^[ #]*CharSet *= *[A-Za-z0-9]*$/CharSet = '$charset'/' \
	$config.bak > $config

chown bin.bin $config
chmod 444 $config

exit 0
