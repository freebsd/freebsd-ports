# $FreeBSD$

PORTNAME=	infamous-plugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.04
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugins for various sound effects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/lib/libfftw3.so:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libntk.so:x11-toolkits/ntk \
		libzita-resampler.so:audio/zita-resampler

USES=		cmake:outsource localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ssj71
GH_PROJECT=	infamousPlugins
USE_GNOME=	cairo

post-patch:
		@${REINPLACE_CMD} -e 's| -g"|"|' \
			${WRKSRC}/src/*/CMakeLists.txt

.include <bsd.port.mk>
