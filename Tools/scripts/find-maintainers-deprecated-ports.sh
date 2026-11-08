#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

PORTSDIR="${PORTSDIR:-/usr/ports}"
MAINTAINER=""

# parse command line arguments
MAINTAINER="$1"

# check PORTSDIR
if [ ! -d "$PORTSDIR" ]; then
    echo "Error: Ports directory $PORTSDIR does not exist." >&2
    exit 1
fi

# check MAINTAINER
if [ -z "$MAINTAINER" ]; then
    MAINTAINER="$(whoami)@FreeBSD.org"
fi

# report maintainer
echo "Maintainer: $MAINTAINER"

stream_ports() {
    categories=$(make -C "$PORTSDIR" -V SUBDIR)
    for category in $categories; do
        category_dir="$PORTSDIR/$category"
        [ -d "$category_dir" ] || continue

        ports=$(make -C "$category_dir" -V SUBDIR 2>/dev/null)
        for port in $ports; do
            port_dir="$category_dir/$port"
            makefile="$port_dir/Makefile"

            if [ -f "$makefile" ]; then
                echo "===> PORT-ORIGIN=$category/$port"
                cat "$makefile"
            fi
        done
    done
}

stream_ports | awk '
BEGIN {
    origin = ""
    maintainer = ""
    deprecated = ""
    expiration = ""
}

/^===> PORT-ORIGIN=/ {
    if (origin != "" && maintainer == "'${MAINTAINER}'" && deprecated != "") {
        print origin
        print "  -> DEPRECATED: " deprecated
        print "  -> EXPIRATION_DATE: " (expiration != "" ? expiration : "[not set]")
    }

    # FIX: "===> PORT-ORIGIN=" is 17 chars. Position 18 is the start of the category name.
    origin = substr($0, 18)
    maintainer = ""
    deprecated = ""
    expiration = ""
    next
}

$1 ~ /^MAINTAINER[ \t]*=/ {
    sub(/^MAINTAINER[ \t]*=[ \t]*/, "")
    maintainer = $0
    next
}

$1 ~ /^DEPRECATED[ \t]*=/ {
    sub(/^DEPRECATED[ \t]*=[ \t]*/, "")
    deprecated = $0
    next
}

$1 ~ /^EXPIRATION_DATE[ \t]*=/ {
    sub(/^EXPIRATION_DATE[ \t]*=[ \t]*/, "")
    expiration = $0
    next
}

END {
    if (origin != "" && maintainer == "'$MAINTAINER'" && deprecated != "") {
        print origin
        print "  -> DEPRECATED: " deprecated
        print "  -> EXPIRATION_DATE: " (expiration != "" ? expiration : "[not set]")
    }
}
'
