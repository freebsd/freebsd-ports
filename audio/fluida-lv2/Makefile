PORTNAME=	fluida
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fluidsynth as LV2 plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		xxd:editors/vim-console
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		compiler:c++11-lang gettext-runtime gmake gnome localbase pkgconfig xorg
USE_GNOME=	cairo
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	Fluida.lv2
GH_TUPLE=	brummer10:libxputty:5c69824:libxputty/libxputty

PLIST_FILES=	lib/lv2/Fluida.lv2/Fluida.so \
		lib/lv2/Fluida.lv2/Fluida.ttl \
		lib/lv2/Fluida.lv2/Fluida_ui.so \
		lib/lv2/Fluida.lv2/manifest.ttl

post-patch: # /proc/cpuinfo is used to check SIMD support in CPU
	@${REINPLACE_CMD} -e 's|/proc/cpuinfo|/dev/null|' ${WRKSRC}/Fluida/Makefile

.include <bsd.port.mk>
