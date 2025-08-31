PORTNAME=	gqrx
PORTVERSION=	2.17.7
DISTVERSIONPREFIX=	v
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	comms hamradio
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Software defined radio receiver powered by GNU Radio and Qt
WWW=		https://gqrx.dk

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

FLAVORS=	qt6 qt5
FLAVOR?=	qt6

USES=		cmake compiler:c++11-lang gl pkgconfig qt:${FLAVOR:S/qt//}

USE_GITHUB=	yes
GH_ACCOUNT=	gqrx-sdr
USE_GL=		gl
_USE_QT_qt5=	core gui network svg widgets
_USE_QT_qt6=	base svg
USE_QT=		${_USE_QT_${FLAVOR}}

CONFLICTS_INSTALL=	gqrx ${FLAVORS:N${FLAVOR}:S/^/${PORTNAME}-/}

# XXX Use Portaudio as Gqrx is invariably linked to it
# (auto-detected and used through Gnuradio CMake files)
CMAKE_ARGS+=	-DLINUX_AUDIO_BACKEND:STRING="Portaudio" \
		-DFORCE_QT${FLAVOR:S/qt//}:BOOL=ON

# XXX Work around Gnuradio 3.8 headers (gnuradio/rpcserver_aggregator.h) still
# using std::unary_function (removed with C++17). This breaks when building
# on FreeBSD 14: error: no template named 'unary_function' in namespace 'std'
CXXFLAGS+=	-D_LIBCPP_ENABLE_CXX17_REMOVED_UNARY_BINARY_FUNCTION

PLIST_FILES=	bin/gqrx \
		share/applications/dk.gqrx.gqrx.desktop \
		share/man/man1/gqrx.1.gz

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/src/gqrx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dk.gqrx.gqrx.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_MAN} ${WRKSRC}/resources/gqrx.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
