PORTNAME=	indi
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.4.2
PORTREVISION=	1
CATEGORIES=	devel astro

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the Instrument-Neutral-Device-Interface protocol
WWW=		https://indilib.org/ \
		https://github.com/indilib/indi/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		nlohmann-json>0:devel/nlohmann-json \
		cpp-httplib>0:www/cpp-httplib
LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		libnova.so:astro/libnova \
		libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora \
		libXISF.so:graphics/libxisf \
		liberfa.so:astro/erfa

USES=		cmake iconv jpeg ninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	indilib

CMAKE_ARGS=	-DINDI_SYSTEM_HTTPLIB=on \
		-DINDI_SYSTEM_JSONLIB=on

USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
