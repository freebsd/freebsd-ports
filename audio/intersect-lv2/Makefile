PORTNAME=	intersect
PORTVERSION=	1.3
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugin expands a stereo input to three channels

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPLv3.txt

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/include/fftw3.h:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sboukortt
GH_PROJECT=	intersect-lv2

PLIST_FILES=	lib/lv2/intersect.lv2/intersect.so \
		lib/lv2/intersect.lv2/intersect.ttl \
		lib/lv2/intersect.lv2/manifest.ttl

post-install: # no need to install an lv2proc-based script
	@${RM} ${STAGEDIR}${PREFIX}/bin/intersect

.include <bsd.port.mk>
