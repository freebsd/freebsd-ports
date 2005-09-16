#!/bin/sh
# Needed to make symlinks/shortcuts work.
# Wrap duke3d binary
cd %%DUKEDIR%%
./duke3d $*
exit $?
