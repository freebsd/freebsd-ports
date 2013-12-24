# Created by: bremner@unb.ca
# $FreeBSD$

PORTNAME=	ipe
PORTVERSION=	7.1.4
DISTVERSIONSUFFIX=	-src
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}${PORTVERSION:R:R}/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible vector graphics editor with Latex text support

LICENSE=	GPLv3 # (or later)

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		liblua-5.2.so:${PORTSDIR}/lang/lua52
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		gmake iconv pkgconfig
USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USE_TEX=	latex
MAKE_ENV=	DLL_CFLAGS="-fPIC" \
		ICONV_CFLAGS="-I${LOCALBASE}/include" \
		ICONV_LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}" \
		INSTALL_DIR="${MKDIR}" \
		INSTALL_FILES="${INSTALL_DATA}" \
		INSTALL_SCRIPTS="${INSTALL_SCRIPT}" \
		INSTALL_PROGRAMS="${INSTALL_PROGRAM}" \
		IPE_USE_ICONV="-DIPE_USE_ICONV" \
		IPEDOCDIR="${DOCSDIR}" \
		IPEMANDIR="${MANPREFIX}/man/man1" \
		IPEPREFIX="${PREFIX}" \
		LUA_CFLAGS="-I${LOCALBASE}/include/lua52" \
		LUA_LIBS="-L${LOCALBASE}/lib -llua-5.2" \
		MOC="${MOC}"
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		ipe.1 ipe6upgrade.1 ipeextract.1 iperender.1 ipetoipe.1 \
		ipescript.1
PORTDOCS=	*

DESKTOP_ENTRIES="Ipe" "" "${DATADIR}/${PORTVERSION}/ipe.png" \
		"${PORTNAME}" "" true

NO_STAGE=	yes
.include <bsd.port.options.mk>

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

post-install:
	(cd ${WRKSRC}/../fontmaps && ${INSTALL_DATA} fontmap.xml \
		${DATADIR}/${PORTVERSION})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/../build/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
