#!/bin/sh
# Needed to make symlinks/shortcuts work.
# Wrap geepee32 binary
cd "/usr/local/geepee32//"
./geepee32 $*
exit $?
