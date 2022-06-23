PORTNAME=	sdr++
DISTVERSION=	1.0.4
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-Platform SDR Software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/license

LIB_DEPENDS=	libad9361.so:misc/libad9361-iio \
		libairspy.so:comms/airspy \
		libfftw3f.so:math/fftw3-float \
		libglfw.so:graphics/glfw \
		libhackrf.so:comms/hackrf \
		libiio.so:misc/libiio \
		librtaudio.so:audio/rtaudio \
		librtlsdr.so:comms/rtl-sdr \
		libSoapySDR.so:misc/soapysdr \
		libvolk.so:devel/volk

USES=		cmake compiler:c++17-lang gl pkgconfig xorg
USE_GL=		gl glew glu opengl
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	AlexandreRouma
GH_PROJECT=	SDRPlusPlus

CMAKE_OFF=	OPT_BUILD_AIRSPYHF_SOURCE # dependency isn't ported yet

.include <bsd.port.mk>
