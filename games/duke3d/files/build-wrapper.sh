#!/bin/sh
# Needed to make symlinks/shortcuts work.
# Wrap build (editor) binary
cd %%DUKEDIR%%
./build $*
exit $?
