# New ports collection makefile for:  rxvt-big5
# Date created:                   Thur Nov 2, 2000
# Whom:                           Michael C . Wu <keichii@iteration.net>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../x11/rxvt

.if !defined(NO_MULTIBYTE_CURSOR)
EXTRA_PATCHES=	${.CURDIR}/files/patch-multibyte_cursor
.endif
PKGMESSAGE=	${.CURDIR}/pkg-message

.include "${MASTERDIR}/Makefile"

PORTNAME=	rxvt
PORTVERSION=	2.6.4

#.include <bsd.port.pre.mk>
PKGNAMEPREFIX:= ${PKGNAMEPREFIX}tw-

MAINTAINER=	keichii@freebsd.org

CONFIGURE_ARGS+= \
		--enable-xim --enable-big5 \
		--enable-next-scroll --with-term=xterm-color
