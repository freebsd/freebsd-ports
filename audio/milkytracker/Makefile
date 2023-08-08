PORTNAME=	milkytracker
PORTVERSION=	1.04.00
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	7e9171488fc47ad2de646a4536794fda21e7303d.patch:-p1

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music creation tool inspired by Fast Tracker 2
WWW=		https://milkytracker.titandemo.org/

LICENSE=	BSD3CLAUSE GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libjack.so:audio/jack \
		liblhasa.so:archivers/lhasa \
		libzzip.so:devel/zziplib

USES=		cmake compiler:c11 cpe sdl
CPE_VENDOR=	milkytracker_project
USE_GITHUB=	yes
GH_PROJECT=	MilkyTracker
USE_SDL=	sdl2

ICONS=		carton.ico carton.png

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

OPTIONS_DEFINE=		DOCS RTMIDI
OPTIONS_DEFAULT=	DOCS RTMIDI

RTMIDI_DESC=	MIDI input support via rtmidi

RTMIDI_LIB_DEPENDS=	libasound.so:audio/alsa-lib \
			librtmidi.so:audio/rtmidi
RTMIDI_CMAKE_ON=	-DENABLE_RTMIDI:BOOL=ON

post-install:
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/resources/pictures/${f} \
		${STAGEDIR}${PREFIX}/share/pixmaps/${f:C/carton/milkytracker/}
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
