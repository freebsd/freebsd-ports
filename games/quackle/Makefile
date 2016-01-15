# Created by: shoemaker@bluebottle.com (Jonathan Shoemaker)
# $FreeBSD$

PORTNAME=	quackle
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Scrabble-like word game utilizing Qt4

LICENSE=	GPLv3

USE_GITHUB=	yes

USES=		compiler:c++11-lib gmake qmake
USE_QT4=	gui moc_build

BUILD_WRKSRC=	${WRKSRC}/quacker

DESKTOP_ENTRIES="Quackle" "${COMMENT}" "" "quackle" "Game;BoardGame;" "true"

post-patch:
	@${REINPLACE_CMD} '/-Wno-unused-local-typedefs/d' \
		${BUILD_WRKSRC}/quacker.pro \
		${WRKSRC}/quackleio/quackleio.pro
	@${REINPLACE_CMD} 's|"data"|"${DATADIR}"|' \
		${BUILD_WRKSRC}/settings.cpp

post-configure:
.for dir in quackleio quacker
	@(cd ${WRKSRC}/${dir} && ${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS})
.endfor

pre-build:
.for dir in . quackleio
	@(cd ${WRKSRC}/${dir} && ${DO_MAKE_BUILD} ${ALL_TARGET})
.endfor

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/Quackle \
		${STAGEDIR}${PREFIX}/bin/quackle
	(cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
