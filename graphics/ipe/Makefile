# Created by: David Bremner <bremner@unb.ca>

PORTNAME=	ipe
PORTVERSION=	7.2.23
DISTVERSIONSUFFIX=	-src
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://dl.bintray.com/otfried/generic/ipe/${PORTVERSION:R}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Extensible vector graphics editor with LaTeX support

LICENSE=	GPLv3+

RUN_DEPENDS=	xdg-open:devel/xdg-utils
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreetype.so:print/freetype2 \
		libgsl.so:math/gsl \
		libpng.so:graphics/png \
		libspiro.so:graphics/libspiro

USES=		compiler:c++11-lib gmake gnome jpeg lua:52 pkgconfig shebangfix qt:5
USE_GNOME=	cairo
USE_QT=		buildtools_build core gui qmake_build widgets
USE_TEX=	pdftex

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
SHEBANG_FILES=	${WRKSRC}/ipecurl/ipecurl.sh

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
		's|\([[:blank:]]\)=|\1?=|' ${WRKSRC}/config.mak

post-install:
	@${LN} -sf ${DATADIR}/${PORTVERSION}/ipe.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libipe*
.for filename in ipe6upgrade iperender ipeextract ipescript ipetoipe ipepresenter ipe
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${filename}
.endfor

.include <bsd.port.mk>
