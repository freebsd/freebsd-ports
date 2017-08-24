# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	swh
DISTVERSION=	1.0.16-4
DISTVERSIONSUFFIX=	-g1aa77e5
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@rawbw.com
COMMENT=	SWH Plugins in LV2 format

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		gmake pkgconfig localbase
USE_GITHUB=	yes
GH_PROJECT=	lv2

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/*.lv2/*.so

.include <bsd.port.mk>
