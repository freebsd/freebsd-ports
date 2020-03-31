# $FreeBSD$

PORTNAME=	jamulus
DISTVERSION=	3.4.4
CATEGORIES=	audio
MASTER_SITES=	SF/llcon/${NAME}/${DISTVERSION}/
DISTNAME=	${NAME}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Internet jam session software

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack

USES=		compiler:c++11-lang qmake qt:5
USE_QT=		core gui network widgets xml buildtools_build

NAME=		Jamulus

WRKSRC=		${WRKDIR}/${NAME}${PORTVERSION}

DESKTOP_ENTRIES=	"${NAME}" "${COMMENT}" "${NAME}" \
			"${PORTNAME}" "AudioVideo;Audio;Mixer;Qt;" true

PLIST_FILES=	bin/${NAME} \
		share/pixmaps/jamulus.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${NAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/res/fronticon.png ${STAGEDIR}${PREFIX}/share/pixmaps/jamulus.png

.include <bsd.port.mk>
