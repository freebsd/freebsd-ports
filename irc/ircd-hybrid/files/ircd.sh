#!/bin/sh
[ -x /usr/local/sbin/ircd ] \
&& /usr/local/sbin/ircd >/dev/null 2>&1 \
&& echo -n " ircd"
