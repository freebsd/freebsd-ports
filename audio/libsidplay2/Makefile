# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsidplay2
PORTVERSION=	2.1.1
PORTREVISION=	3
CATEGORIES=	audio emulators
MASTER_SITES=	SF/sidplay2/sidplay2/sidplay-libs-${PORTVERSION}
DISTNAME=	sidplay-libs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to play Commodore 64 SID-tunes cycle accurately

USES=		gmake pathfix pkgconfig
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	builders/hardsid-builder/configure \
		builders/resid-builder/configure \
		libsidplay/configure \
		libsidutils/configure \
		resid/configure
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/sidplay/builders

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/libsidutils/src/ini/ini.cpp

.include <bsd.port.mk>
