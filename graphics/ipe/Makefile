# Created by: David Bremner <bremner@unb.ca>
# $FreeBSD$

PORTNAME=	ipe
PORTVERSION=	7.1.7
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}${PORTVERSION:R:R}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible vector graphics editor with LaTeX support

LICENSE=	GPLv3 # (or later)

RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		dos2unix gmake iconv jpeg lua:52 pkgconfig
DOS2UNIX_FILES=	ipelib/Makefile
USE_GNOME=	cairo
USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USE_TEX=	pdftex
MAKE_ENV=	DL_LIBS="" \
		DLL_CFLAGS="-fPIC" \
		ICONV_CFLAGS="-I${ICONV_PREFIX}/include" \
		ICONV_LIBS="-L${ICONV_PREFIX}/lib ${ICONV_LIB}" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILES="${INSTALL_DATA}" \
		INSTALL_SCRIPTS="${INSTALL_SCRIPT}" \
		INSTALL_PROGRAMS="${INSTALL_PROGRAM}" \
		INSTALL_ROOT="${STAGEDIR}" \
		IPE_USE_ICONV="-DIPE_USE_ICONV" \
		IPEDOCDIR="${DOCSDIR}" \
		IPEMANDIR="${MANPREFIX}/man/man1" \
		IPEPREFIX="${PREFIX}" \
		JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		LUA_CFLAGS="-I${LUA_INCDIR}" \
		LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}" \
		MOC="${MOC}"
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

PORTDOCS=	*

DESKTOP_ENTRIES="Ipe" "" "${DATADIR}/${PORTVERSION}/ipe.png" \
		"${PORTNAME}" "" true

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC}/../fontmaps && ${SED} -e \
		's|/usr/share|${LOCALBASE}/share| ; \
		 s|type1/gsfonts|ghostscirpt/fonts|' \
		< gsfonts-fontmap.xml > fontmap.xml
	@${REINPLACE_CMD} -e \
		's|^INSTALL_|#INSTALL_| ; \
		 /-O2/s|^|#|' ${WRKSRC}/common.mak
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)=|\1?=|' ${WRKSRC}/config.mak
	@${REINPLACE_CMD} -e \
		'/$$(INSTALL_ROOT)$$(IPEDOCDIR)/s|^|#|' ${WRKSRC}/ipe/Makefile
	@${REINPLACE_CMD} -e \
		'/%s/s|gnome-open|xdg-open|' ${WRKSRC}/ipe/lua/prefs.lua
	@${REINPLACE_CMD} -e \
		's|QT__H|QT_H|' ${WRKSRC}/ipeui/ipeui_qt.h

post-install:
	(cd ${WRKSRC}/../fontmaps && ${INSTALL_DATA} fontmap.xml \
		${STAGEDIR}${DATADIR}/${PORTVERSION})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/../build/doc && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
