PORTNAME=	zita-resampler
DISTVERSION=	1.8.0
CATEGORIES=	audio
MASTER_SITES=	https://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	meka@tilda.center
COMMENT=	C++ library for resampling audio signals
WWW=		https://kokkinizita.linuxaudio.org/linuxaudio/zita-resampler/resampler.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake tar:bzip2
USE_LDCONFIG=	yes

CXXFLAGS_amd64+=	-DENABLE_SSE2

.include <bsd.port.mk>
