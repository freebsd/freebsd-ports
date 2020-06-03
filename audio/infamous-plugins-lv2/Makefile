# $FreeBSD$

PORTNAME=	infamous-plugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LV2 plugins for various sound effects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		casynth_ui_main.cxx:181:5: error: cannot initialize a member subobject of type 'LV2UI_Handle'

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		${LOCALBASE}/lib/libfftw3.so:math/fftw3
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libntk.so:x11-toolkits/ntk \
		libzita-resampler.so:audio/zita-resampler

USES=		cmake compiler gnome localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ssj71
GH_PROJECT=	infamousPlugins
USE_GNOME=	cairo

.include <bsd.port.pre.mk>

post-patch:
		@${REINPLACE_CMD} -e 's| -g"|"|' \
			${WRKSRC}/src/*/CMakeLists.txt
.if ${CHOSEN_COMPILER_TYPE} == gcc
		@${REINPLACE_CMD} -e 's| -Og"|"|' \
			${WRKSRC}/src/*/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
