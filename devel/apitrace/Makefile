PORTNAME=	apitrace
DISTVERSION=	12.0
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
		snappy>0:archivers/snappy

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libbacktrace.so:devel/libbacktrace \
		libpng.so:graphics/png \
		libsnappy.so:archivers/snappy

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig python shebangfix xorg
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	apitrace
GH_PROJECT=	apitrace
GH_TUPLE=	microsoft:DirectXMath:e95d848:DirectXMath/thirdparty/directxmath

SHEBANG_FILES=	scripts/*.py

OPTIONS_DEFINE=		DOCS QT5 WAFFLE
OPTIONS_DEFAULT=	QT5 WAFFLE
OPTIONS_SUB=		yes

QT5_USES=		qt:5
QT5_USE=		QT=core,gui,network,widgets,buildtools:build,qmake:build
QT5_CMAKE_BOOL=		ENABLE_GUI

WAFFLE_DESC=		Use Waffle library to allow retrace on Wayland, headless etc.
WAFFLE_LIB_DEPENDS=	libwaffle-1.so:graphics/waffle
WAFFLE_CMAKE_BOOL=	ENABLE_WAFFLE

LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|__linux__|__unix__|' ${WRKSRC}/retrace/glstate_images.cpp

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt

post-install-QT5-on:
	${INSTALL_DATA} ${FILESDIR}/qapitrace.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
