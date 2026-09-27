#!/bin/sh
#
# MAINTAINER: yuri@FreeBSD.org

PORTSDIR="${PORTSDIR:-/usr/ports}"
SHOW_ALL=0
MAINTAINER=""

# parse command line arguments
if [ "$1" == "-all" ]; then
    SHOW_ALL=1
    shift
fi
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

stream_ports | awk -v show_all="$SHOW_ALL" '
BEGIN {
    origin = ""
    maintainer = ""
    has_broken = 0
    broken_reason = ""
    broken_count = 0
    if_depth = 0
    uncond_count = 0
    cond_count = 0
}

/^===> PORT-ORIGIN=/ {
    if (origin != "" && maintainer == "'$MAINTAINER'") {
        if (has_broken) {
            uncond[++u] = origin "\n  -> BROKEN: " broken_reason
            uncond_count++
        } else if (broken_count > 0) {
            cond[++c] = origin
            cond_count++
            for (i = 1; i <= broken_count; i++) {
                cond[++c] = "  -> " broken_lines[i]
            }
        }
    }

    # "===> PORT-ORIGIN=" is 17 chars. Position 18 is the start of the origin.
    origin = substr($0, 18)
    maintainer = ""
    has_broken = 0
    broken_reason = ""
    broken_count = 0
    if_depth = 0
    next
}

$1 ~ /^MAINTAINER[ \t]*=/ {
    sub(/^MAINTAINER[ \t]*=[ \t]*/, "")
    maintainer = $0
    next
}

$0 ~ /^\.if([ \t]|$)/ {
    if_depth++
    next
}

$0 ~ /^\.endif([ \t]|$)/ {
    if (if_depth > 0) {
        if_depth--
    }
    next
}

$1 ~ /^BROKEN[ \t]*=/ {
    sub(/^BROKEN[ \t]*=[ \t]*/, "")
    if (if_depth > 0) {
        broken_lines[++broken_count] = "BROKEN (inside .if/.endif): " $0
    } else {
        has_broken = 1
        broken_reason = $0
    }
    next
}

$1 ~ /^BROKEN_[A-Za-z0-9_]+[ \t]*=/ {
    line = $0
    match(line, /^BROKEN_[A-Za-z0-9_]+/)
    var_name = substr(line, RSTART, RLENGTH)
    sub(/^BROKEN_[A-Za-z0-9_]+[ \t]*=[ \t]*/, "", line)
    broken_lines[++broken_count] = var_name ": " line
    next
}

END {
    if (origin != "" && maintainer == "'$MAINTAINER'") {
        if (has_broken) {
            uncond[++u] = origin "\n  -> BROKEN: " broken_reason
            uncond_count++
        } else if (broken_count > 0) {
            cond[++c] = origin
            cond_count++
            for (i = 1; i <= broken_count; i++) {
                cond[++c] = "  -> " broken_lines[i]
            }
        }
    }

    print "=== List of unconditionally broken ports ==="
    if (uncond_count == 0) {
        print "(none)"
    } else {
        for (i = 1; i <= u; i++) {
            print uncond[i]
        }
    }
    print "Total: " uncond_count " port" (uncond_count == 1 ? "" : "s")

    if (show_all == 1) {
        print ""
        print ""
        print "=== List of conditionally broken ports ==="
        if (cond_count == 0) {
            print "(none)"
        } else {
            for (i = 1; i <= c; i++) {
                print cond[i]
            }
        }
        print "Total: " cond_count " port" (cond_count == 1 ? "" : "s")
    }
}
'
