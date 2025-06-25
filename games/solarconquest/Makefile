PORTNAME=	solarconquest
PORTVERSION=	0.2
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	http://games.sajthelper.com/ \
		LOCAL/ehaupt \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	SolarConquest

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space 2D action game with plenty of shooting
WWW=		http://games.sajthelper.com/

USES=		gl dos2unix sdl
USE_SDL=	sdl mixer image
USE_GL=		yes
DOS2UNIX_FILES=	makefile source/MenuScreen.h source/main.cpp

MAKEFILE=	makefile

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|images/|${DATADIR}/images/|' \
		${WRKSRC}/source/main.cpp
	@${REINPLACE_CMD} -e 's|shapes/|${DATADIR}/shapes/|' \
		${WRKSRC}/source/main.cpp
	@${REINPLACE_CMD} -e 's|settings.dat|.solarconquest.rc|' \
		${WRKSRC}/source/Common.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/solar ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}/shapes
	${INSTALL_DATA} ${WRKSRC}/shapes/* ${STAGEDIR}${DATADIR}/shapes
	${MKDIR} ${STAGEDIR}${DATADIR}/images/fonts
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${STAGEDIR}${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/fonts/* ${STAGEDIR}${DATADIR}/images/fonts

.include <bsd.port.mk>
