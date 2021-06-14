PORTNAME=	tetraproc
DISTVERSION=	0.8.6
CATEGORIES=	audio
MASTER_SITES=	http://kokkinizita.linuxaudio.org/linuxaudio/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tetrahedral microphone processor for ambisonic recording

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	freetype2>0:print/freetype2
LIB_DEPENDS=	libclthreads.so:devel/clthreads \
		libclxclient.so:devel/clxclient \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libjack.so:audio/jack \
		libpng16.so:graphics/png \
		libsndfile.so:audio/libsndfile

USES=		gmake localbase:ldflags pkgconfig tar:bz2 xorg
USE_XORG=	x11 xft

WRKSRC_SUBDIR=	source

PLIST_FILES=	bin/tetrafile \
		bin/tetraproc \
		share/${PORTNAME}/k20-meterH0.png \
		share/${PORTNAME}/k20-meterH1.png \
		share/${PORTNAME}/k20-scaleH.png

post-install:
	@cd ${STAGEDIR}${PREFIX} && ${STRIP_CMD} \
		bin/tetrafile \
		bin/tetraproc

.include <bsd.port.mk>
