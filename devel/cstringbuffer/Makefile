# New ports collection makefile for:   cStringBuffer
# Date created:        10 July 2004
# Whom:                Mooneer Salem <mooneer@translator.cx>
#
# $FreeBSD$
#

PORTNAME=	cstringbuffer
PORTVERSION=	0.1.5
CATEGORIES=	devel
MASTER_SITES=	http://www.translator.cx/dist/libs/

MAINTAINER=	mooneer@translator.cx
COMMENT=	File-like IO for strings

USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
MAN3=		csb.3
MANCOMPRESSED=	no

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
