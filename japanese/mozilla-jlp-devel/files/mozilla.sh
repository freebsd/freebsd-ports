#!/bin/sh

LANG=@LOCALENAME@; export LANG
@LIBXPG4@

cd @PREFIX@/lib/mozilla-devel
exec ./mozilla "$@"
