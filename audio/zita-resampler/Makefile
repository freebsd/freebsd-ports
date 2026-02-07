PORTNAME=	zita-resampler
DISTVERSION=	1.11.2
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	meka@tilda.center
COMMENT=	C++ library for resampling audio signals
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/zita-resampler/resampler.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake tar:xz
USE_LDCONFIG=	yes

CXXFLAGS_amd64+=	-DENABLE_SSE2

OPTIONS_DEFINE=		OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-ffast-math

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
