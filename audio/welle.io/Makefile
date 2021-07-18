PORTNAME=	welle.io
DISTVERSION=	2.3
CATEGORIES=	audio hamradio

MAINTAINER=	nsonack@outlook.com
COMMENT=	SDR DAB/DAB+ Receiver

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfaad.so:audio/faad \
		libmp3lame.so:audio/lame \
		libmpg123.so:audio/mpg123
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cmake compiler:c++11-lang pkgconfig qt:5
USE_QT=		charts core declarative gui multimedia network quickcontrols2 \
		widgets buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	AlbrechtL
GH_TAGNAME=	66675c9a4160c644a5ade5bf7a0cd0647647f33c

OPTIONS_DEFINE=		AIRSPY CLI FFTW RTLSDR SOAPY
OPTIONS_DEFAULT=	FFTW RTLSDR

RTLSDR_DESC=	RTL-SDR support
AIRSPY_DESC=	AirSpy support
SOAPY_DESC=	SoapySDR support
FFTW_DESC=	Use FFTW3 instead of KISSFFT
CLI_DESC=	Build the welle-cli tool

RTLSDR_LIB_DEPENDS=	librtlsdr.so:comms/rtl-sdr
RTLSDR_CMAKE_BOOL=	RTLSDR

FFTW_CMAKE_BOOL_OFF=	KISS_FFT
FFTW_LIB_DEPENDS=	libfftw3f.so:math/fftw3-float
FFTW_BUILD_DEPENDS=	fftw3>=0:math/fftw3

CLI_CMAKE_BOOL=		BUILD_WELLE_CLI
CLI_PLIST_FILES=	bin/welle-cli \
			share/welle-io/html/index.html \
			share/welle-io/html/index.js

SOAPY_CMAKE_BOOL=	SOAPYSDR
SOAPY_LIB_DEPENDS=	libSoapySDR.so:misc/soapysdr

AIRSPY_CMAKE_BOOL=	AIRSPY
AIRSPY_LIB_DEPENDS=	libairspy.so:comms/airspy

.include <bsd.port.mk>
