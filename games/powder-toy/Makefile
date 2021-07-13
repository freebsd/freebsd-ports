PORTNAME=	powder-toy
PORTVERSION=	96.2.350
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	'Falling sand' physics sandbox with air pressure and velocity support

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libfftw3.so:math/fftw3 \
		libluajit-5.1.so:lang/luajit-openresty \
		libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	The-Powder-Toy
GH_PROJECT=	The-Powder-Toy

USES=		compiler:c++11-lang meson pkgconfig python:build sdl
USE_SDL=	sdl2

PORTDOCS=	README.md changelog.txt

OPTIONS_DEFINE=		DOCS SSE
OPTIONS_DEFAULT_amd64=	SSE

SSE_DESC=		Enable SSE optimizations
SSE_MESON_ON=		-Dx86_sse=auto
SSE_MESON_OFF=		-Dx86_sse=none

post-patch:
	@${REINPLACE_CMD} -e 's|python3|${PYTHON_CMD}|' ${WRKSRC}/meson.build

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/powder ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/resources/powder.desktop ${STAGEDIR}${PREFIX}/share/applications/powder-toy.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/appdata
	${INSTALL_DATA} ${WRKSRC}/resources/powder.appdata.xml ${STAGEDIR}${PREFIX}/share/appdata/powder-toy.appdata.xml
.for s in 16 24 32 48 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/resources/icon/powder-${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/powder-toy.png
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/icon/powder-32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/powder-toy.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
