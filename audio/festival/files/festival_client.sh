#!/bin/sh
PATH=@PKG_PREFIX@/libexec:$PATH
export PATH
exec festival_client.naked @PKG_FESTIVAL_LOCATION@/lib $*
