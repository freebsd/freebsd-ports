#!/bin/sh
# Needed to make symlinks/shortcuts work.
# Wrap lsdldoom binary
cd %%INSTALLDIR%%
./lsdldoom -nocheckwadversion $*
exit $?
