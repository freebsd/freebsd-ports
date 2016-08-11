# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	violetland
PORTVERSION=	0.4.3
PORTREVISION=	6
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Top-down survival shoot 'em up

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs

USE_GITHUB=	yes
GH_ACCOUNT=	ooxi

USES=		cmake dos2unix gettext
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
DOS2UNIX_FILES=	CMakeLists.txt src/system/utility/FileUtility.cpp
CMAKE_ARGS=	-DDATA_INSTALL_DIR="${DATADIR}"

PLIST_FILES=	bin/violetland \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/set.libList/ s|)| ${LOCALBASE}/lib/libintl.so&|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icon-light.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG README_EN.TXT README_RU.TXT \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
