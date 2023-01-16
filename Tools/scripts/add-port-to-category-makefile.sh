#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

PORT="$1"

set -e
set -o pipefail

##
## add-port-to-category-makefile.sh: adds a new port to {category}/Makefile
##


# sanity checks
[ -z "$PORT" ] && echo "this command requires the <port> argument" && exit 1
(echo "$PORT" | grep -q "/") && echo "port's name can't contain slash" && exit 1
! [ -f Makefile ] && echo "no Makefile found, are you in the ports tree?" && exit 1
! grep -q "^    SUBDIR += " Makefile && echo "this command can only be run from the ports tree category directory" && exit 1
! grep -q "^\\.include <bsd\\.port\\.subdir\\.mk>$" Makefile && echo "this command can only be run from the ports tree category directory" && exit 1
! [ -d "$PORT" ] && echo "the '$PORT' directory is missing" && exit 1
! [ -f "$PORT/Makefile" ] && echo "'$PORT/Makefile' is missing" && exit 1
grep -q "^    SUBDIR += $PORT$" Makefile && echo "port '$PORT' is already added" && exit 1


# add port to Makefile
/usr/bin/awk '
BEGIN {
	done = 0
	seen = 0
	str = "    SUBDIR += '$PORT'"
}
/^    SUBDIR \+= / {
	if (!done && str < $0) {
		print str
		done = 1
	}
	print $0;
	seen = seen + 1
}
!/^    SUBDIR \+= / {
	if (seen > 0 && !done) {
		print str
		done = 1
	}
	print $0
}' < Makefile > Makefile.new &&
/bin/mv Makefile.new Makefile
