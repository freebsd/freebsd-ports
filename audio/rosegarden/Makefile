PORTNAME=	rosegarden
DISTVERSION=	25.12
CATEGORIES=	audio
MASTER_SITES=	https://sourceforge.net/projects/${PORTNAME}/files/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	General purpose music editor and sequencer suite
WWW=		https://www.rosegardenmusic.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dssi_osc_update:audio/dssi \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3f.so:math/fftw3-float \
		liblilv-0.so:audio/lilv \
		liblrdf.so:textproc/liblrdf \
		liblo.so:audio/liblo \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libjack.so:audio/jack
RUN_DEPENDS=	dssi_osc_update:audio/dssi \
		flac:audio/flac \
		wavpack:audio/wavpack \
		xdg-open:devel/xdg-utils \
		lilypond:print/lilypond

USES=		cmake compiler:c++11-lib desktop-file-utils \
		localbase:ldflags pkgconfig shared-mime-info tar:xz \
		qt:6
USE_QT=		base 5compat tools:build

OPTIONS_DEFINE=		LIRC

LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CMAKE_ON=		-DENABLE_LIRC:BOOL=ON

CMAKE_ON=	USE_QT6

.include <bsd.port.mk>
