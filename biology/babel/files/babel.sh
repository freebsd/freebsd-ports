#!/bin/sh
# $FreeBSD$

export BABEL_DIR=${BABEL_DIR-@PREFIX@/share/babel}

exec @PREFIX@/libexec/babel "$@"
