#!/bin/sh
#
# $FreeBSD$
#
# Run KLH10 with KS-ITS hardware configuration and ITS OS configuration
# to bring up MIT Incompatible Timesharing System emulation.

in_network=false
for i in `groups`; do
    if [ $i = network ]; then
	in_network=true
	break
    fi
done

if [ `whoami` = root ]; then
    in_network=true
fi

if [ $in_network = false ]; then
    echo WARNING: You must be in group network in order to run a networked ITS.
    echo WARNING: You may still run a non-networked ITS.
fi

if [ ! -r ~/.itsrc ]; then
    echo its: My config file '(~/.itsrc)' is missing!
    echo its: Did you remember to run its-user-install\?
    echo its: Terminating.
    exit 1
fi

set -e   # croak on corrupt config file.
. ~/.itsrc
set +e

if [ "$KLH10_HOME" = "" ]; then
    echo its: KLH10_HOME is missing from my config file.
    echo its: terminating.
    exit 1
elif [ ! -d "$KLH10_HOME" ]; then
    echo its: $KLH10_HOME is not a directory.
    echo its: terminating.
    exit 1
fi

if [ "$PI_IMAGE" = "" ]; then
    echo its: PI_IMAGE is missing from my config file.
    echo its: Terminating.
    exit 1
elif [ ! -w "$PI_IMAGE" ]; then
    echo its: $PI_IMAGE is not a writable file.
    echo its: Terminating.
    exit 1
fi

cd $KLH10_HOME
exec lockf -t 0 -k $PI_IMAGE kn10-ks klh10-kn-freebsd.ini
