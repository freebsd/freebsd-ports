PORTNAME=	indi
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.3
CATEGORIES=	devel astro

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the Instrument-Neutral-Device-Interface protocol
WWW=		https://www.indilib.org/ \
		https://github.com/indilib/indi

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LGPL

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libXISF.so:graphics/libxisf \
		libcfitsio.so:astro/cfitsio \
		libcurl.so:ftp/curl \
		libev.so:devel/libev \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		libnova.so:astro/libnova \
		libogg.so:audio/libogg \
		libtheora.so:multimedia/libtheora

USES=		cmake jpeg iconv ninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	indilib

USE_LDCONFIG=	yes

PLIST_SUB=	SOVERSION=${DISTVERSION}

.include <bsd.port.mk>
