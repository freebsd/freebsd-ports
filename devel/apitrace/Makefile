PORTNAME=	apitrace
DISTVERSION=	14.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tools for tracing OpenGL and other graphics APIs
WWW=		https://apitrace.github.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	googletest>0:devel/googletest \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libbacktrace.so:devel/libbacktrace \
		libbrotlidec.so:archivers/brotli \
		libbrotlienc.so:archivers/brotli \
		libpng.so:graphics/png \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd

USES=		cmake:testing compiler:c++17-lang gl localbase:ldflags pkgconfig \
		python qt:6 shebangfix xorg
USE_GITHUB=	yes
GH_TUPLE=	microsoft:DirectXMath:apr2025:DirectXMath/thirdparty/directxmath \
		facebook:zstd:v1.5.7:zstd/thirdparty/zstd
USE_GL=		opengl
USE_QT=		base
USE_XORG=	x11

SHEBANG_FILES=	scripts/*.py

CMAKE_ON=	ENABLE_QT6

OPTIONS_DEFINE=		DOCS WAFFLE
OPTIONS_DEFAULT=	WAFFLE
OPTIONS_SUB=		yes

WAFFLE_DESC=		Use Waffle library to allow retrace on Wayland, headless etc.
WAFFLE_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAFFLE_LIB_DEPENDS=	libwaffle-1.so:graphics/waffle
WAFFLE_CMAKE_BOOL=	ENABLE_WAFFLE

post-patch:
	${REINPLACE_CMD} 's|__linux__|__unix__|' \
		${WRKSRC}/retrace/glstate_images.cpp
	${REINPLACE_CMD} 's/0.0-unknown/${DISTVERSION}/g' \
		${WRKSRC}/cmake/GenerateVersion.cmake

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt
	${INSTALL_DATA} ${FILESDIR}/qapitrace.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
