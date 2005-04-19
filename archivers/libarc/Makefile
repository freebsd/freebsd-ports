# New ports collection makefile for:	libarc
# Date Created:				20 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libarc
PORTVERSION=	2.0.2
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.onicos.com/staff/iz/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny C decompression library for several popular compression formats

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I." PREFIX="${PREFIX}" LN="${LN} -sf"

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
