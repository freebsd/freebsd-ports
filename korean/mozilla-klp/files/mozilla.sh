#!/bin/sh

LANG=@LOCALENAME@; export LANG

cd @PREFIX@/lib/mozilla
exec ./mozilla "$@"
