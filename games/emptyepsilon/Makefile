# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	emptyepsilon
DISTVERSIONPREFIX=	EE-
DISTVERSION=	2017.11.03
CATEGORIES=	games

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spaceship bridge simulator game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: scienceDatabase.cpp: call of overloaded 'abs(float)' is ambiguous

LIB_DEPENDS=	libsfml-system.so:devel/sfml

USE_GITHUB=	yes
GH_ACCOUNT=	daid
GH_PROJECT=	EmptyEpsilon SeriousProton:sproton

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
