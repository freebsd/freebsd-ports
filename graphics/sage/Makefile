# New ports collection makefile for:   sage
# Date created:        4 February 2005
# Whom:                Janni
#
# $FreeBSD$
#

PORTNAME=	sage
PORTVERSION=	0.1.1
CATEGORIES=	graphics devel
MASTER_SITES=	ftp://ftp.worldforge.org/pub/worldforge/libs/sage/ \
		http://purple.worldforge.org/downloads/libs/sage/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	worldforge

MAINTAINER=	jannisan@t-online.de
COMMENT=	OpenGL extension library

USE_SDL=	sdl
USE_GL=		yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CFLAGS=		-I${X11BASE}/include
CONFIGURE_ENV=	"CFLAGS=${CFLAGS}"

post-patch:
	${REINPLACE_CMD} s/sdl-config/sdl11-config/g ${WRKSRC}/configure

.include <bsd.port.mk>
