PORTNAME=	indi
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.2.1
CATEGORIES=	devel astro

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the Instrument-Neutral-Device-Interface protocol
WWW=		https://www.indilib.org/ \
		https://github.com/indilib/indi

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libnova.so:astro/libnova \
		libcurl.so:ftp/curl \
		libgsl.so:math/gsl \
		libfftw3.so:math/fftw3 \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg \
		libev.so:devel/libev \
		libXISF.so:graphics/libxisf

USES=		cmake jpeg iconv ninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	indilib

USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION:R}

.include <bsd.port.mk>
