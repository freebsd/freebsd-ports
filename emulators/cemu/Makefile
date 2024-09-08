PORTNAME=	cemu
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	emulators

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	TI-84 Plus CE and TI-83 Premium CE calculator emulator
WWW=		https://ce-programming.github.io/CEmu/

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++11-lang desktop-file-utils gl libarchive pkgconfig \
		qmake qt:5 shared-mime-info
USE_GL=		gl
USE_QT=		buildtools:build core gui network widgets

USE_GITHUB=	yes
GH_ACCOUNT=	CE-Programming
GH_PROJECT=	CEmu
GH_TUPLE=	CE-Programming:zdis:7eb89e5:zdis/core/debug/zdis \
		adriweb:tivars_lib_cpp:f627164:tvlc/gui/qt/tivars_lib_cpp

QMAKE_SOURCE_PATH=	gui/qt/CEmu.pro
_ICON_PREFIX=	${PREFIX}/share/icons/hicolor

post-install:
	${LN} -s CEmu ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/gui/qt/resources/linux/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/gui/qt/resources/linux/${PORTNAME}.xml \
		${STAGEDIR}${PREFIX}/share/mime/packages
.for n in 16 20 22 24 32 36 40 42 48 64 72 96 128 160 192 256 512
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${n}x${n}/apps
	${INSTALL_DATA} \
	    ${WRKSRC}/gui/qt/resources/icons/linux/${PORTNAME}-${n}x${n}.png \
		${STAGEDIR}${_ICON_PREFIX}/${n}x${n}/apps/${PORTNAME}.png
.endfor

.include <bsd.port.mk>
