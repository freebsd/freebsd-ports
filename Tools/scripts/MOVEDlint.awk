#!/usr/bin/awk -f
#
# Copyright (c) 2004 Oliver Eikemeier. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#
# $FreeBSD$
#
# MOVEDlint - check MOVED for consistency
#
# Usage:
#  [env PORTSDIR=/usr/ports] /usr/ports/Tools/scripts/MOVEDlint.awk
#

BEGIN {
    FS = "|"
    portsdir = ENVIRON["PORTSDIR"] ? ENVIRON["PORTSDIR"] : "/usr/ports"
    if (ARGC == 1) {
        ARGV[ARGC++] = portsdir "/MOVED"
        if (ENVIRON["BLAME"]) {
            if (!system("test -d " portsdir "/.svn")) {
                blame = "cd " portsdir "; svn blame MOVED 2>/dev/null"
            } else if (!system("test -d " portsdir "/.git")) {
                blame = "cd " portsdir "; git blame MOVED 2>/dev/null"
            }

        }
    }
    sort = "/usr/bin/sort -n"
    lastdate="1999-12-31"
}

/^(#|$)/ {
    next
}

NF != 4 {
    printf "%5d: format is from|to|date|reason, detected %d field(s) \n", NR, NF | sort
    error[NR] = 1
    next
}

$1 !~ /^[^\/]+\/[^\/]+$/ || $2 !~ /^([^\/]+\/[^\/]+)?$/ {
    printf "%5d: source and destination must be category/port\n", NR | sort
    error[NR] = 1
    next
}

$3 !~ /^20[0-3][0-9]-[01][0-9]-[0-3][0-9]$/ {
    printf "%5d: missing YYYY-MM-DD date\n", NR | sort
    error[NR] = 1
    next
}

{
    if (lastdate > $3) {
        printf "%5d: date going backwards from %s to %s\n", NR, lastdate, $3 | sort
        error[NR] = 1
    }
    lastdate = $3

    from_flavor=""
    if ($1 ~ "@") {
        from_flavor=$1
        sub("@.*", "", $1)
        sub(".*@", "", from_flavor)
    }

    if (system("test -f " portsdir "/" $1 "/Makefile")) {
        delete missing[$1]
    } else {
        if (from_flavor != "") {
            if (!system("test \"" from_flavor "\" = \"`make -C " portsdir "/" $1 " -VFLAVORS:M" from_flavor "`\"")) {
                printf "%5d: %s still has the %s flavor\n", NR, $1, from_flavor | sort
            }
            # No else because the port is there but does not have the flavor,
            # so it should be ok.
        } else {
            printf "%5d: %s must be marked as resurrected\n", NR, $1 | sort
        }
    }

    if ($2) {
        to_flavor=""
        if ($2 ~ "@") {
            to_flavor=$2
            sub("@.*", "", $2)
            sub(".*@", "", to_flavor)
        }

        if (system("test -f " portsdir "/" $2 "/Makefile"))
            missing[$2] = NR
        else
            if (to_flavor != "") {
                if (system("test \"" to_flavor "\" = \"`make -C " portsdir "/" $2 " -VFLAVORS:M" to_flavor "`\"")) {
                    printf "%5d: %s does not have the %s flavor\n", NR, $2, to_flavor | sort
                    error[NR] = 1
                }
            }
    }

#    Produces too many false positives
#    if ($4 ~ /^[a-z].*/) {
#       printf "Initial value of 'reason' is lowercase: %5d (%s)\n", NR, $4 | sort
#       error[NR] = 1
#    }

    if ($4 ~ /\.$/) {
        printf "%5d: Final character is a dot: (%s)\n", NR, $4 | sort
        error[NR] = 1
    }
}

END {
    for (port in missing) {
        printf "%5d: %s not found\n", missing[port], port | sort
        error[missing[port]] = 1
    }

    if (blame) {
        line = 1
        while (blame | getline) {
            if (error[line])
                printf "%5d!\n%5d! %s\n", line, line, $0 | sort
            line++
        }
        close(blame)
    }

    close(sort)
}
