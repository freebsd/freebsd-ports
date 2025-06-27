PORTNAME=	apitrace
DISTVERSION=	13.0
CATEGORIES=	devel

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Tools for tracing OpenGL and other graphics APIs
WWW=		https://apitrace.github.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	brotli>0:archivers/brotli \
		googletest>0:devel/googletest \
		libbacktrace>0:devel/libbacktrace \
		png>0:graphics/png \
		vulkan-headers>0:graphics/vulkan-headers \
		snappy>0:archivers/snappy

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libbacktrace.so:devel/libbacktrace \
		libpng.so:graphics/png \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++17-lang desktop-file-utils localbase:ldflags pkgconfig python qt:6 shebangfix xorg
USE_XORG=	x11

USE_GITHUB=	yes
GH_TUPLE=	microsoft:DirectXMath:e95d848:DirectXMath/thirdparty/directxmath

SHEBANG_FILES=	scripts/*.py

OPTIONS_DEFINE=		DOCS WAFFLE
OPTIONS_DEFAULT=	WAFFLE
OPTIONS_SUB=		yes

USE_QT=			base
USE_GL=			gl opengl
CMAKE_ON=		ENABLE_QT6

WAFFLE_DESC=		Use Waffle library to allow retrace on Wayland, headless etc.
WAFFLE_BUILD_DEPENDS=	wayland-protocols>=0:graphics/wayland-protocols
WAFFLE_LIB_DEPENDS=	libwaffle-1.so:graphics/waffle
WAFFLE_CMAKE_BOOL=	ENABLE_WAFFLE

post-patch:
	${REINPLACE_CMD} -e 's|__linux__|__unix__|' ${WRKSRC}/retrace/glstate_images.cpp

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt
	${INSTALL_DATA} ${FILESDIR}/qapitrace.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
