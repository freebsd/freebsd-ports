#!/bin/sh
# Needed to make symlinks/shortcuts work.
# Wrap lsdldoom binary
cd %%DUKEDIR%%
./duke3d $*
exit $?
