PORTNAME=	powder-toy
DISTVERSIONPREFIX=	v
DISTVERSION=	99.3.384
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	'Falling sand' physics sandbox with air pressure and velocity support
WWW=		https://powdertoy.co.uk/ \
		https://github.com/The-Powder-Toy/The-Powder-Toy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libfftw3.so:math/fftw3 \
		libcurl.so:ftp/curl \
		libpng.so:graphics/png \
		libjsoncpp.so:devel/jsoncpp

USES=		compiler:c++17-lang desktop-file-utils luajit \
		meson pkgconfig python:build sdl
USE_GITHUB=	yes
GH_ACCOUNT=	The-Powder-Toy
GH_PROJECT=	The-Powder-Toy
USE_SDL=	sdl2
MESON_ARGS=	-Dapp_exe="${PORTNAME}"
CXXFLAGS_i386=	-msse

CONFLICTS_INSTALL=powder-toy-devel

PORTDOCS=	README.md changelog.txt

OPTIONS_DEFINE=		DOCS SSE
OPTIONS_DEFAULT_amd64=	SSE

SSE_DESC=		Enable SSE optimizations
SSE_MESON_ON=		-Dx86_sse=auto
SSE_MESON_OFF=		-Dx86_sse=none

post-patch:
	@${REINPLACE_CMD} -e "s|'python3'|'${PYTHON_CMD}'|" ${WRKSRC}/meson.build

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/powder-toy ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${BUILD_WRKSRC}/resources/powder.desktop ${STAGEDIR}${PREFIX}/share/applications/uk.co.powdertoy.tpt.desktop  # as mentioned in appdata
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${BUILD_WRKSRC}/resources/appdata.xml ${STAGEDIR}${PREFIX}/share/appdata/powder-toy.appdata.xml
.for s in 16 24 32 48 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/generated_icons/icon_exe_16.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/16x16/apps/powder-toy.png
	${INSTALL_DATA} ${WRKSRC}/resources/generated_icons/icon_exe_32.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/24x24/apps/powder-toy.png # for e.g. lxpanel
	${INSTALL_DATA} ${WRKSRC}/resources/generated_icons/icon_exe_32.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps/powder-toy.png
	${INSTALL_DATA} ${WRKSRC}/resources/generated_icons/icon_exe_48.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/powder-toy.png
	${INSTALL_DATA} ${WRKSRC}/resources/generated_icons/icon_exe.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/powder-toy.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
