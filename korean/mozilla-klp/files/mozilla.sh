#!/bin/sh

LANG=@LOCALENAME@; export LANG
@LIBXPG4@

cd @PREFIX@/lib/mozilla
exec ./mozilla "$@"
