#!/bin/sh
# $Id$
# ports/Tools/scripts/BDB-upgrade-helper.sh
#
# A helper script to upgrade applications that used to depend on
# BerkeleyDB ports 4.0...4.7 to use a newer version of BerkeleyDB.
#
# Written by Matthias Andree in 2014, and placed under the same
# license as FreeBSD itself, see /COPYRIGHT or /usr/src/COPYRIGHT.

set -eu
: ${PREFIX:=/usr/local}
: ${LOCALBASE:=${PREFIX}}

# check requisites
tool=
if   [ -x ${LOCALBASE}/sbin/portmaster ] ; then tool=portmaster ;
elif [ -x ${LOCALBASE}/sbin/portupgrade ]; then tool=portupgrade;
else
    echo >&2 "Neither portmaster nor portupgrade installed. Cannot continue."
    echo >&2 "Please install ports-mgmt/portmaster before proceeding."
    exit 1
fi

# check BerkeleyDB 4.0...4.7 versions
rx='db4[1-7]?(-nocrypto)?-4'
if pkg -N 2>/dev/null ; then pkg=yes ; else pkg= ; fi
if [ -n "$pkg" ] ; then
    # pkg
    dbnames=$(pkg info -x "$rx")
else
    # old pkg_*
    dbnames=$(pkg_info -E -X "$rx")
fi

# due to set -e, the script will not reach this point
# unless there have been matched packages - without packages,
# pkg_info or pkg will exit with failure.

# check if we need to pass in origins or package names
if [ "$tool" = portupgrade ] ; then
    if [ -n "$pkg" ] ; then
	dbnames=$(printf '%s\n' "$dbnames" | xargs -n1 pkg info -q -o)
    else
	dbnames=$(printf '%s\n' "$dbnames" | xargs -n1 pkg_info -q -o)
    fi
fi

# generate the upgrade command
case "$tool" in
portmaster)
    cmd="portmaster -R"
    for i in $dbnames ; do cmd="$cmd -r $i" ; done
    ;;
portupgrade)
    cmd="portupgrade -f -r"
    for i in $dbnames ; do cmd="$cmd -x $i" ; done
    for i in $dbnames ; do cmd="$cmd $i" ; done
    ;;
*)
    echo >&2 "Internal error in $0." ; exit 1
    ;;
esac

echo "+ $cmd"
$cmd

# due to set -e, the script will not reach this point
# if there was an error or failure with the upgrade tool

if [ -n "$pkg" ] ; then
    pkg delete $dbnames
else
    pkg_delete $dbnames
fi

echo "Success."
