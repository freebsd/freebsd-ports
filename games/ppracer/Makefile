# New ports collection makefile for:	PlanetPenguin Racer
# Date created:				28 May, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppracer
DISTVERSION=	0.5alpha
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D downhill racing game... kind of like TuxRacer Improved

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_SDL=	mixer sdl
USE_GL=		gl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		-e 's,libpng12,libpng14,g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,RacingMode::,,' ${WRKSRC}/src/racingmode.h

.include <bsd.port.mk>
