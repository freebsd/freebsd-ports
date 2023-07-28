PORTNAME=	zplugins
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	audio multimedia
PKGNAMESUFFIX=	-lv2

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of LV2 plugins to be bundled with Zrythm
WWW=		https://github.com/zrythm/ZPlugins

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2 \
		bash:shells/bash \
		gmake:devel/gmake \
		${LOCALBASE}/lib/libztoolkit.a:x11-toolkits/ztoolkit
LIB_DEPENDS=	liblo.so:audio/liblo \
		libsndfile.so:audio/libsndfile

USES=		gnome guile:2.2,3.0,build,alias meson pkgconfig xorg
USE_GNOME=	cairo glib20 librsvg2
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	zrythm
GH_PROJECT=	ZPlugins

BINARY_ALIAS=	make=${GMAKE}

.include <bsd.port.mk>
