# New ports collection makefile for:	solarconquest
# Date created:		06 Apr 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	solarconquest
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://games.sajthelper.com/ \
		${MASTER_SITE_LOCAL} \
		http://mirror.amdmi3.ru/distfiles/
MASTER_SITE_SUBDIR=	ehaupt
DISTNAME=	SolarConquest

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space 2D action game with plenty of shooting

USE_SDL=	sdl mixer image
USE_GL=		yes
USE_DOS2UNIX=	makefile source/MenuScreen.h source/main.cpp

MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's|images/|${DATADIR}/images/|' \
		${WRKSRC}/source/main.cpp
	@${REINPLACE_CMD} -e 's|shapes/|${DATADIR}/shapes/|' \
		${WRKSRC}/source/main.cpp
	@${REINPLACE_CMD} -e 's|settings.dat|.solarconquest.rc|' \
		${WRKSRC}/source/Common.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/solar ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${DATADIR}/shapes
	${INSTALL_DATA} ${WRKSRC}/shapes/* ${DATADIR}/shapes
	${MKDIR} ${DATADIR}/images/fonts
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/fonts/* ${DATADIR}/images/fonts

.include <bsd.port.mk>
