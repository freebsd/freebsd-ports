# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsidplay2
PORTVERSION=	2.1.1
PORTREVISION=	4
CATEGORIES=	audio emulators
MASTER_SITES=	SF/sidplay2/sidplay2/sidplay-libs-${PORTVERSION}
DISTNAME=	sidplay-libs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to play Commodore 64 SID-tunes cycle accurately

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/libsidutils/src/ini/ini.cpp

.include <bsd.port.mk>
