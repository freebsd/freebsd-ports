# New ports collection makefile for:   cStringBuffer
# Date created:        10 July 2004
# Whom:                Mooneer Salem <mooneer@translator.cx>
#
# $FreeBSD$
#

PORTNAME=	cstringbuffer
PORTVERSION=	0.1.6
CATEGORIES=	devel
MASTER_SITES=	# disappeared

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File-like IO for strings

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAN3=		csb.3
MANCOMPRESSED=	no

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	include/csb.h lib/libcsb.a lib/libcsb.la lib/libcsb.so \
		lib/libcsb.so.1

.include <bsd.port.mk>
