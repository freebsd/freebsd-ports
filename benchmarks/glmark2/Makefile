# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glmark2
PORTVERSION=	2020.04
PORTREVISION=	1
CATEGORIES=	benchmarks

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c50755b5a193.patch:-p1 # https://github.com/glmark2/glmark2/issues/125
PATCHFILES+=	ca6e78769306.patch:-p1 # https://github.com/glmark2/glmark2/issues/125

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Benchmark for OpenGL (ES) 2.0

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++11-lang gl jpeg localbase:ldflags pkgconfig \
		waf
USE_GL=		egl gl glesv2
USE_GITHUB=	yes
GH_TAGNAME=	06e4728
CONFIGURE_ARGS=	--with-flavors=${PLATFORMS:ts,} --no-opt --no-debug

PORTDOCS=	NEWS

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	PLATFORM
OPTIONS_MULTI_PLATFORM=	DRM WAYLAND X11
OPTIONS_DEFAULT=DRM WAYLAND X11
OPTIONS_SUB=	yes

PLATFORM_DESC=		Window systems

DRM_DESC=		KMS console support
DRM_LIB_DEPENDS=	libudev.so:devel/libudev-devd \
			libdrm.so:graphics/libdrm
DRM_USE=		GL=gbm
DRM_VARS=		PLATFORMS+="drm-gl drm-glesv2"

WAYLAND_BUILD_DEPENDS=	wayland-protocols>=1.12:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_VARS=		PLATFORMS+="wayland-gl wayland-glesv2"

X11_USES=		xorg
X11_USE=		XORG=x11
X11_VARS=		PLATFORMS+="x11-gl x11-glesv2"

post-patch:
	@${REINPLACE_CMD} -e '/-std=c++/s,14,11,' ${WRKSRC}/wscript
	@${REINPLACE_CMD} -e "/lib/s/, 'dl'//" ${WRKSRC}/src/wscript_build
	@${REINPLACE_CMD} -e 's/GLMARK_VERSION/ &/' \
		${WRKSRC}/src/native-state-x11.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
