# New ports collection makefile for:	libsidplay2
# Date created:				6 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsidplay2
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sidplay2
DISTNAME=	sidplay-libs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to play Commodore 64 SID-tunes cycle accurate

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/libsidutils/src/ini/ini.cpp

.include <bsd.port.mk>
