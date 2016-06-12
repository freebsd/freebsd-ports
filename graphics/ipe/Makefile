# Created by: David Bremner <bremner@unb.ca>
# $FreeBSD$

PORTNAME=	ipe
PORTVERSION=	7.2.3
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	https://dl.bintray.com/otfried/generic/ipe/${PORTVERSION:R}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extensible vector graphics editor with LaTeX support

LICENSE=	GPLv3+

RUN_DEPENDS=	xdg-open:devel/xdg-utils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		compiler:c++11-lib gmake jpeg lua:52 pkgconfig
USE_GNOME=	cairo
USE_QT5=	widgets buildtools_build qmake_build
USE_TEX=	pdftex
MAKE_ENV=	DL_LIBS="" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILES="${INSTALL_DATA}" \
		INSTALL_SCRIPTS="${INSTALL_SCRIPT}" \
		INSTALL_PROGRAMS="${INSTALL_PROGRAM}" \
		INSTALL_ROOT="${STAGEDIR}" \
		IPEDOCDIR="${DOCSDIR}" \
		IPEMANDIR="${MANPREFIX}/man/man1" \
		IPEPREFIX="${PREFIX}" \
		JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		LUA_PACKAGE="lua-${LUA_VER}" \
		MOC="${MOC}"
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

PORTDOCS=	*

DESKTOP_ENTRIES="Ipe" "" "ipe" "ipe" "" ""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^INSTALL_|#INSTALL_| ; \
		 /-O2/s|^|#|' ${WRKSRC}/common.mak
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)=|\1?=|' ${WRKSRC}/config.mak
	@${REINPLACE_CMD} -e \
		'/%s/s|gnome-open|xdg-open|' ${WRKSRC}/ipe/lua/prefs.lua

post-install:
	@${LN} -sf ${DATADIR}${PORTVERSION}/ipe.png \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
