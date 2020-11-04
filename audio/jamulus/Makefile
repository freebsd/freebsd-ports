# $FreeBSD$

PORTNAME=	jamulus
DISTVERSIONPREFIX=	r
DISTVERSION=	3_6_0
CATEGORIES=	audio
#MASTER_SITES=	SF/llcon/${NAME}/${DISTVERSION}/ # it is unclear whether SF or GH should be used because SF doesn't have 3.6.0, but README on GH claims that it is hosted on SF
DISTNAME=	${NAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet jam session software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5
USE_QT=		concurrent core gui network widgets xml buildtools_build linguisttools_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	corrados

NAME=		Jamulus

DESKTOP_ENTRIES=	"${NAME}" "${COMMENT}" "${NAME}" \
			"${PORTNAME}" "AudioVideo;Audio;Mixer;Qt;" true

PLIST_FILES=	bin/${NAME} \
		share/pixmaps/jamulus.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${NAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/res/fronticon.png ${STAGEDIR}${PREFIX}/share/pixmaps/jamulus.png

.include <bsd.port.mk>
