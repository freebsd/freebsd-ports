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
#  [env PORTSDIR=/usr/ports] awk -f MOVEDlint.awk /usr/ports/MOVED
#

BEGIN {
    FS = "|"
    portsdir = ENVIRON["PORTSDIR"] ? ENVIRON["PORTSDIR"] : "/usr/ports"
    sort = "/usr/bin/sort -n"
    lastdate="1999-12-31"
}

/^#/ {
    next
}

NF != 4 {
    printf "%5d: illegal format\n", NR | sort
    next
}

$1 !~ /^[^\/]+\/[^\/]+$/ || $2 !~ /^([^\/]+\/[^\/]+)?$/ {
    printf "%5d: source and destination must be category/port\n", NR | sort
    next
}
 
$3 !~ /^20[0-3][0-9]-[01][0-9]-[0-3][0-9]$/ {
    printf "%5d: missing YYYY-MM-DD date\n", NR | sort
    next
}

{
    if (lastdate > $3)
        printf "%5d: date going backwards from %s to %s\n", NR, lastdate, $3 | sort
    lastdate = $3

    if (system("test -f " portsdir "/" $1 "/Makefile"))
        delete missing[$1]
    else
        resurrected[$1] = NR

    if ($2)
        if (system("test -f " portsdir "/" $2 "/Makefile"))
            missing[$2] = NR
        else
            delete resurrected[$2]
}

END {
    for (port in resurrected)
        printf "%5d: %s must be marked as resurrected\n", resurrected[port], port | sort

    for (port in missing)
        printf "%5d: %s not found\n", missing[port], port | sort

    close(sort)
}
