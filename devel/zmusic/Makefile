PORTNAME=	zmusic
PORTVERSION=	1.1.8
CATEGORIES=	devel

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	GZDoom's music system as a standalone library

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/gplv3.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/licenses/lgplv3.txt

LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
		libfluidsynth.so:audio/fluidsynth

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	coelckers
GH_PROJECT=	ZMusic

USE_LDCONFIG=	yes
CMAKE_OFF=	DYN_SNDFILE DYN_FLUIDSYNTH

OPTIONS_DEFINE=	ALSA
OPTIONS_DEFAULT=	ALSA
ALSA_CMAKE_BOOL=	SYSTEM_MIDI
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

.include <bsd.port.mk>
