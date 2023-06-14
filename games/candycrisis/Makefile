PORTNAME=	candycrisis
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pure action and puzzle gaming
WWW=		https://github.com/jorio/CandyCrisis

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake desktop-file-utils pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	jorio
GH_PROJECT=	CandyCrisis
USE_SDL=	sdl2

DESKTOP_ENTRIES=	"Candy Crisis" \
			"An exciting combination of pure action and puzzle gaming!" \
			"candycrisis" \
			"candycrisis" \
			"Game;" \
			""

SUB_FILES=	candycrisis

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/CandyCrisisResources
	${INSTALL_SCRIPT} ${WRKDIR}/candycrisis ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/CandyCrisis \
		${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/CandyCrisisResources/* \
		${STAGEDIR}${DATADIR}/CandyCrisisResources/
	${INSTALL_DATA} ${WRKSRC}/packaging/candycrisis-desktopicon.png \
		${STAGEDIR}${PREFIX}/share/icons/candycrisis.png

.include <bsd.port.mk>
