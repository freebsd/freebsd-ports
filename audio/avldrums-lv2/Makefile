# $FreeBSD$

PORTNAME=	avldrums
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.4
CATEGORIES=	audio
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dedicated AVLDrumkits LV2 Plugin

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2

USES=		gl gmake gnome pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	x42
GH_PROJECT=	${PORTNAME}.lv2
GH_TUPLE=	x42:robtk:bad6354:robtk/robtk
USE_GL=		gl glu
USE_GNOME=	glib20 pango cairo
USE_XORG=	x11

MAKE_ENV=	avldrums_VERSION=${PORTVERSION}

PLIST_FILES=	lib/lv2/avldrums.lv2/Black_Pearl_4_LV2.sf2 \
		lib/lv2/avldrums.lv2/Red_Zeppelin_4_LV2.sf2 \
		lib/lv2/avldrums.lv2/avldrums.so \
		lib/lv2/avldrums.lv2/avldrums.ttl \
		lib/lv2/avldrums.lv2/avldrumsUI_gl.so \
		lib/lv2/avldrums.lv2/manifest.ttl

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFAULT_amd64=	SSE
OPTIONS_DEFAULT_i386=	SSE

SSE_MAKE_ARGS=		PORT_SIMD_FLAGS="-msse -msse2 -mfpmath=sse"

.include <bsd.port.mk>
