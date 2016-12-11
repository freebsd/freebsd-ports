# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	emptyepsilon
PORTVERSION=	2016.09.02
DISTVERSIONPREFIX=	EE-
CATEGORIES=	games

MAINTAINER=	yuri@rawbw.com
COMMENT=	Spaceship bridge simulator game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsfml-system.so:devel/sfml

USE_GITHUB=	yes
GH_TUPLE=	daid:EmptyEpsilon:${DISTVERSIONFULL}
GH_TUPLE+=	daid:SeriousProton:${DISTVERSIONFULL}:sproton

USES=		cmake compiler:c++11-lib
USE_GL=		gl glu
CMAKE_ARGS=	-DSERIOUS_PROTON_DIR="${WRKSRC_sproton}/"

post-patch:
	@${REINPLACE_CMD} -e 's|basepath + |"${DATADIR}/" + basepath + |' \
		${WRKSRC_sproton}/src/resources.cpp
	@${REINPLACE_CMD} -e 's|loadFromFile("resources/"|loadFromFile("${DATADIR}/resources/"|' \
		${WRKSRC_sproton}/src/postProcessManager.cpp

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/EmptyEpsilon ${STAGEDIR}${PREFIX}/bin/emptyepsilon

.include <bsd.port.mk>
