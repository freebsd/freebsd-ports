# New ports collection makefile for:  rxvt-big5
# Date created:                   Thur Nov 2, 2000
# Whom:                           Michael C . Wu <keichii@iteration.net>
#
# $FreeBSD$
#

CATEGORIES=	chinese

MASTERDIR=	${.CURDIR}/../../x11/rxvt
.include "${MASTERDIR}/Makefile"

PORTNAME=	rxvt
PORTVERSION=	2.6.4

#.include <bsd.port.pre.mk>
PKGNAMEPREFIX:=	${PKGNAMEPREFIX}cn-

MAINTAINER=	keichii@freebsd.org

CONFIGURE_ARGS+=	--enable-xim --enable-big5 \
			--enable-next-scroll --with-term=xterm-color
