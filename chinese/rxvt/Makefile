# New ports collection Makefile for: rxvt
# Date created:         Nov 16 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=      ${.CURDIR}/../../x11/rxvt-devel

.include "${MASTERDIR}/Makefile"

MAINTAINER=	keichii@freebsd.org

CONFIGURE_ARGS+= \
		--enable-menubar --enable-graphics \
		--disable-backspace-key --disable-delete-key \
		--enable-rxvt-scroll --enable-next-scroll \
		--with-encoding=big5
