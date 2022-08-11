PORTNAME=	gqrx
PORTVERSION=	2.15.9
PORTREVISION=	1
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	comms hamradio

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Software defined radio receiver powered by GNU Radio and Qt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnuradio-runtime.so:comms/gnuradio \
		libgnuradio-analog.so:comms/gnuradio \
		libgnuradio-blocks.so:comms/gnuradio \
		libgnuradio-filter.so:comms/gnuradio \
		libgnuradio-fft.so:comms/gnuradio \
		libgnuradio-digital.so:comms/gnuradio \
		libgnuradio-pmt.so:comms/gnuradio \
		libgnuradio-osmosdr.so:comms/gr-osmosdr \
		libboost_system.so:devel/boost-libs \
		liblog4cpp.so:devel/log4cpp \
		libgmpxx.so:math/gmp \
		libgmp.so:math/gmp \
		libvolk.so:devel/volk \
		libfftw3f.so:math/fftw3-float \
		libfftw3f_threads.so:math/fftw3-float \
		liborc-0.4.so:devel/orc \
		libasound.so:audio/alsa-lib \
		libjack.so:audio/jack \
		libportaudio.so:audio/portaudio

USES=		cmake compiler:c++11-lang gl pkgconfig qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	gqrx-sdr
USE_GL=		gl
USE_QT=		core gui network svg widgets

# XXX Use Portaudio as Gqrx is invariably linked to it
# (auto-detected and used through Gnuradio CMake files)
CMAKE_ARGS+=	-DLINUX_AUDIO_BACKEND:STRING="Portaudio"

PLIST_FILES=	bin/gqrx \
		share/applications/dk.gqrx.gqrx.desktop \
		man/man1/gqrx.1.gz

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/gqrx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dk.gqrx.gqrx.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/resources/gqrx.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
