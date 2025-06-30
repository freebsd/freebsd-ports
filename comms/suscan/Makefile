PORTNAME=	suscan
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	comms hamradio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Channel scanner based on sigutils library
WWW=		https://github.com/BatchDrake/suscan

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	\
		libasound.so:audio/alsa-lib \
		libfftw3f.so:math/fftw3-float \
		libsigutils.so:comms/sigutils \
		libsndfile.so:audio/libsndfile \
		libSoapySDR.so:misc/soapysdr \
		libvolk.so:devel/volk

USES=		cmake:noninja gnome pkgconfig # build breaks with ninja
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	BatchDrake

.include <bsd.port.mk>
