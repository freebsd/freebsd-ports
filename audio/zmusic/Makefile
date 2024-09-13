PORTNAME=	zmusic
DISTVERSION=	1.1.12
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	GZDoom's music system as a standalone library
WWW=		https://github.com/coelckers/ZMusic

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/gplv3.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/licenses/lgplv3.txt

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libgme.so:audio/libgme \
		libmpg123.so:audio/mpg123 \
		libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	coelckers
GH_PROJECT=	ZMusic

USE_LDCONFIG=	yes

EXTRACT_AFTER_ARGS+=	--exclude thirdparty/fluidsynth \
			--exclude thirdparty/game-music-emu \
			--exclude thirdparty/zlib

CMAKE_OFF=	DYN_MPG123 DYN_SNDFILE 

OPTIONS_DEFINE=	ALSA
OPTIONS_DEFAULT=	ALSA
ALSA_CMAKE_BOOL=	SYSTEM_MIDI
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

.include <bsd.port.mk>
