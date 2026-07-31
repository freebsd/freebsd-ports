PORTNAME=	sdrangel
DISTVERSION=	7.27.1
CATEGORIES=	comms hamradio

MAINTAINER=	res2500@ukr.net
COMMENT=	Software defined radio application and signal analyzer
WWW=		https://github.com/f4exb/sdrangel

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		flac:audio/flac \
		airspyhf_rx:comms/airspyhf \
		opencv_version:graphics/opencv \
		vulkan-headers>=1.4:graphics/vulkan-headers

LIB_DEPENDS=	libcodec2.so:audio/codec2 \
		libfftw3f.so:math/fftw3-float \
		libhackrf.so:comms/hackrf \
		librtlsdr.so:comms/rtl-sdr \
		libairspy.so:comms/airspy \
		libairspyhf.so:comms/airspyhf \
		libSoapySDR.so:misc/soapysdr \
		libsndfile.so:audio/libsndfile \
		libfaad.so:audio/faad \
		libopencv_core.so:graphics/opencv \
		libopus.so:audio/opus \
		libhamlib.so:comms/hamlib \
		libhidapi.so:comms/hidapi \
		libavcodec.so:multimedia/ffmpeg \
		libFLAC.so:audio/flac
USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	f4exb
GH_TAGNAME=	v${DISTVERSION}

USE_QT=		base charts declarative location multimedia positioning scxml \
		serialport speech svg tools webchannel webengine websockets
USE_GL=		gl glu

CMAKE_ARGS=	-DENABLE_QT6=ON \
		-DBUILD_GUI=ON \
		-DBUILD_SERVER=OFF \
		-DBUILD_BENCH=OFF \
		-DENABLE_LIBUNWIND=OFF \
		-DENABLE_AIRSPY=ON \
		-DENABLE_HACKRF=ON \
		-DENABLE_RTLSDR=ON \
		-DENABLE_SOAPYSDR=ON \
		-DENABLE_BLADERF=OFF \
		-DENABLE_IIO=OFF \
		-DENABLE_LIMESUITE=OFF \
		-DENABLE_SDRPLAY=OFF \
		-DENABLE_USRP=OFF \
		-DENABLE_XTRX=OFF \
		-DENABLE_PERSEUS=OFF \
		-DENABLE_MIRISDR=OFF \
		-DENABLE_FOBOS=OFF

.include <bsd.port.mk>
