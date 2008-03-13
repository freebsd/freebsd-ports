# New ports collection makefile for:	PlanetPenguin Racer
# Date created:				28 May, 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppracer
DISTVERSION=	0.5alpha
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D downhill racing game... kind of like TuxRacer Improved

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SDL=	mixer sdl
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${X11BASE},g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,RacingMode::,,' ${WRKSRC}/src/racingmode.h

.include <bsd.port.mk>
