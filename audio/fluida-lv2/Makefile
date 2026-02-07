PORTNAME=	fluida
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.5
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2
MASTER_SITES=	https://github.com/brummer10/Fluida.lv2/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	${PORTNAME}
DISTNAME=	Fluida.lv2-${DISTVERSIONFULL}-src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fluidsynth as LV2 plugin
WWW=		https://github.com/brummer10/Fluida.lv2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		xxd:editors/vim
LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		compiler:c++11-lang gettext-runtime gmake gnome localbase pkgconfig tar:xz xorg
USE_GNOME=	cairo glib20
USE_XORG=	x11
USE_BINUTILS=	yes # linking needs some GNU features, fails on 12 without this, see https://github.com/brummer10/GxPlugins.lv2/issues/9

WRKSRC=		${WRKDIR}/Fluida.lv2-${DISTVERSIONFULL}

ALL_TARGET=

PLIST_FILES=	lib/lv2/Fluida.lv2/Fluida.so \
		lib/lv2/Fluida.lv2/Fluida.ttl \
		lib/lv2/Fluida.lv2/Fluida_ui.so \
		lib/lv2/Fluida.lv2/manifest.ttl

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch: # /proc/cpuinfo is used to check SIMD support in CPU
	@${REINPLACE_CMD} -e 's|/proc/cpuinfo|/dev/null|' ${WRKSRC}/Fluida/Makefile

.include <bsd.port.mk>
