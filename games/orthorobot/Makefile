PORTNAME=	orthorobot
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1-1
DISTVERSIONSUFFIX=	-g48f0742
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Perspective puzzle game

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	zip:archivers/zip
# Does not work with LÖVE 11.
RUN_DEPENDS=	love10:devel/love10

USE_GITHUB=	yes
GH_ACCOUNT=	Stabyourself

NO_ARCH=	yes

DESKTOP_ENTRIES="Ortho Robot" "${COMMENT}" "${WRKSRC}/textavatar.png" \
		"${PORTNAME}" "Game;LogicGame;" false

SUB_FILES=	${PORTNAME}
SUB_LIST=	LOVE_CMD=${LOVE_CMD} PORTNAME=${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} ${DATADIR}/${PORTNAME}.love

LOVE_CMD=	${LOCALBASE}/bin/love10

do-build:
	cd ${WRKSRC} && zip -9 -r ${PORTNAME}.love .

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.love ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
