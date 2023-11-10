PORTNAME=	quackle
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	games

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Crossword game artificial intelligence and analysis tool
WWW=		https://people.csail.mit.edu/jasonkb/quackle/

# dictionaries may not be distributed apart from Quackle
# forbid selling to be on the safe side
LICENSE=	GPLv3Quackle
LICENSE_NAME=	GPLv3 with Quackle dictionary exception
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

USES=		cmake qt:5
USE_GITHUB=	yes
USE_QT=		core qmake:build buildtools:build gui widgets

CMAKE_SOURCE_PATH=	${WRKSRC}/quacker
DESKTOP_ENTRIES=	"Quackle" "Crossword game artificial intelligence and analysis tool" \
			"${DATADIR}/IconSmall.png" "Quackle" "Game;BoardGame;Languages;" false
SUB_FILES=	Quackle

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Quackle ${STAGEDIR}${PREFIX}/libexec/
	(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/ '! -name CMakeLists.txt')
	${INSTALL_DATA} ${WRKSRC}/IconSmall.png ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/Quackle ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
