#!/bin/sh
[ -x /usr/local/tetrinet-x/tetrix.freebsd ] && cd /usr/local/tetrinet-x && \
tetrix.freebsd > /dev/null && echo -n ' tetrinet-x'

