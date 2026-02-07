PORTNAME=	sigdigger
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0-1
DISTVERSIONSUFFIX=	-gb4b4045
PORTREVISION=	2
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-based digital signal analyzer
WWW=		https://batchdrake.github.io/SigDigger/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libportaudio.so:audio/portaudio \
		libsigutils.so:comms/sigutils \
		libsuscan.so:comms/suscan \
		libsuwidgets.so:comms/suwidgets \
		libsndfile.so:audio/libsndfile \
		libSoapySDR.so:misc/soapysdr \
		libvolk.so:devel/volk

USES=		desktop-file-utils gl gnome pkgconfig qmake qt:5
USE_QT=		core gui network opengl widgets buildtools:build
USE_GNOME=	libxml2
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	BatchDrake
GH_PROJECT=	SigDigger

QMAKE_ARGS=	SUWIDGETS_PREFIX=${LOCALBASE}

.include <bsd.port.mk>
