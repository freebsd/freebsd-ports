PORTNAME=	wavetral
DISTVERSION=	g20210517
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convert between single cycle waveforms and audio spectra

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile

USES=		cmake compiler:c++11-lang localbase:ldflags pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	jeanette-c
GH_TAGNAME=	57290f2

PLIST_FILES=	bin/wavetral \
		man/man1/wavetral.1.gz

.include <bsd.port.mk>
