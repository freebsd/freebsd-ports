# New ports collection makefile for:	libsidplay2
# Date created:				6 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsidplay2
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	audio emulators
MASTER_SITES=	SF/sidplay2/sidplay2/sidplay-libs-${PORTVERSION}
DISTNAME=	sidplay-libs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to play Commodore 64 SID-tunes cycle accurate

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	builders/hardsid-builder/configure \
		builders/resid-builder/configure \
		libsidplay/configure \
		libsidutils/configure \
		resid/configure
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/libsidutils/src/ini/ini.cpp

.include <bsd.port.mk>
