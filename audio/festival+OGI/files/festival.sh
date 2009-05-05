#!/bin/sh
# path for audsp
PATH=@PKG_PREFIX@/libexec:$PATH
export PATH
exec festival.naked  --libdir @PKG_FESTIVAL_LOCATION@/lib $*
