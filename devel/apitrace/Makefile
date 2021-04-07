PORTNAME=	apitrace
DISTVERSION=	9.0
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/a17r/${GH_PROJECT}/commit/
# use system brotli: https://github.com/apitrace/apitrace/pull/610
PATCHFILES=	cd3486343001d6a47.patch:-p1 \
		b0f5a220c41af013d.patch:-p1

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Tools for tracing OpenGL and other graphics APIs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libpng.so:graphics/png

USES=		cmake compiler:c++11-lang pkgconfig python:3.5+ shebangfix xorg
USE_GITHUB=	yes
USE_XORG=	x11

SHEBANG_FILES=	scripts/*.py

OPTIONS_DEFINE=		DOCS QT5 WAFFLE
OPTIONS_DEFAULT=	QT5 WAFFLE
OPTIONS_SUB=		yes

WAFFLE_DESC=	Use Waffle library to allow retrace on Wayland, headless etc.

QT5_USES=	qt:5
QT5_USE=	QT=core,gui,network,widgets,buildtools_build,qmake_build
QT5_CMAKE_BOOL=	ENABLE_GUI

WAFFLE_LIB_DEPENDS=	libwaffle-1.so:graphics/waffle
WAFFLE_CMAKE_BOOL=	ENABLE_WAFFLE

post-patch:
	${REINPLACE_CMD} -e 's|__linux__|__unix__|' ${WRKSRC}/retrace/glstate_images.cpp

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/LICENSE.txt

post-install-QT5-on:
	${INSTALL_DATA} ${FILESDIR}/qapitrace.desktop ${STAGEDIR}${PREFIX}/share/applications

.include <bsd.port.mk>
