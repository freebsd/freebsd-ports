PORTNAME=	indi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.1
CATEGORIES=	devel

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the Instrument-Neutral-Device-Interface protocol

LICENSE=	LGPL21

BROKEN_FreeBSD_11=	error: use of undeclared identifier 'TIME_UTC'

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libcfitsio.so:astro/cfitsio \
		libnova.so:astro/libnova \
		libcurl.so:ftp/curl \
		libgsl.so:math/gsl \
		libfftw3.so:math/fftw3 \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg

USES=		cmake jpeg iconv ninja pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	indilib

USE_LDCONFIG=	yes

.include <bsd.port.mk>
