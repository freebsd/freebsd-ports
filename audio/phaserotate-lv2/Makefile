PORTNAME=	phaserotate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Phase rotation LV2 plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	x42
GH_PROJECT=	${PORTNAME}.lv2

MAKE_ARGS=	LV2VERSION=${DISTVERSION}

CONFLICTS_INSTALL=	x42-plugins-lv2 # lib/lv2/phaserotate.lv2/phaserotate.so

PLIST_FILES=	lib/lv2/phaserotate.lv2/manifest.ttl \
		lib/lv2/phaserotate.lv2/phaserotate.so \
		lib/lv2/phaserotate.lv2/phaserotate.ttl

.include <bsd.port.mk>
