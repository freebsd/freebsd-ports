#!/bin/sh
# Needed to make symlinks/shortcuts work.
# Wrap geepee32 binary
cd %%GEEPEE32DIR%%
./geepee32 $*
exit $?
