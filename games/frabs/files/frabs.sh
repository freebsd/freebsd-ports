#!/bin/sh
# $FreeBSD$
rm -f ~/.abuse/sd_cache.tmp
exec abuse.sdl -datadir "%%DATADIR%%" "$@"
