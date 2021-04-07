PORTNAME=	cli-visualizer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8-27
DISTVERSIONSUFFIX=	-g4fc1552
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CLI based audio visualizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libpulse.so:audio/pulseaudio

USES=		cmake compiler:c++14-lang localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	dpayne

PLIST_FILES=	bin/vis

.include <bsd.port.mk>
