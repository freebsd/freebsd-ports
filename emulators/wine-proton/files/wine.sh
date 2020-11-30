#!/bin/sh
TARGET="`realpath $0`"
export WINESERVER=${WINESERVER-${TARGET}server32}
exec "${TARGET}32" "$@"
