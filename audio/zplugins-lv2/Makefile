PORTNAME=	zplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.4
CATEGORIES=	audio multimedia
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LV2 plugins to be bundled with Zrythm

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash \
		gmake:devel/gmake \
		guile2>0:lang/guile2 \
		${LOCALBASE}/lib/libztoolkit.a:x11-toolkits/ztoolkit
LIB_DEPENDS=	liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile

USES=		gnome meson pkgconfig xorg
USE_GNOME=	cairo glib20 librsvg2
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	zrythm
GH_PROJECT=	ZPlugins

BINARY_ALIAS=	make=${GMAKE}

.include <bsd.port.mk>
