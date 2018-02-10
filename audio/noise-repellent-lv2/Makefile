# $FreeBSD$

PORTNAME=	noise-repellent
DISTVERSION=	0.1.4
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin for broadband noise reduction

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	lucianodato

PLIST_FILES=	lib/lv2/nrepel.lv2/manifest.ttl \
		lib/lv2/nrepel.lv2/nrepel.so \
		lib/lv2/nrepel.lv2/nrepel.ttl

.include <bsd.port.mk>
