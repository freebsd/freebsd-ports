# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	emptyepsilon
DISTVERSIONPREFIX=	EE-
DISTVERSION=	2021.03.16
CATEGORIES=	games

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spaceship bridge simulator game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsfml-system.so:devel/sfml

USES=		cmake compiler:c++11-lib gl xorg
USE_GL=		gl glu

USE_GITHUB=	yes
GH_ACCOUNT=	daid
GH_PROJECT=	EmptyEpsilon SeriousProton:sproton

CMAKE_ARGS=	-DSERIOUS_PROTON_DIR="${WRKSRC_sproton}/"

post-patch:
	@${REINPLACE_CMD} -e 's|basepath + |"${DATADIR}/" + basepath + |' \
		${WRKSRC_sproton}/src/resources.cpp
	@${REINPLACE_CMD} -e 's|loadFromFile("resources/"|loadFromFile("${DATADIR}/resources/"|' \
		${WRKSRC_sproton}/src/postProcessManager.cpp
	@${REINPLACE_CMD} -e 's|uint32_t bswap32(uint32_t value)|uint32_t bswap32_(uint32_t value)|' \
		${WRKSRC_sproton}/src/i18n.cpp

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/EmptyEpsilon ${STAGEDIR}${PREFIX}/bin/emptyepsilon

.include <bsd.port.mk>
