# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	texworks
PORTVERSION=	0.4.5
CATEGORIES=	editors
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-r${VCS_REVISION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple TeX front-end program

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS LUA PYTHON

BUILD_DEPENDS=	hunspell:${PORTSDIR}/textproc/hunspell
LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4

USES=		pkgconfig
USE_QT4=	qmake_build gui corelib rcc_build moc_build uic_build \
		dbus xml scripttools designer_build
QMAKEFLAGS=	QMAKE_LFLAGS="-lz"
QMAKE_ARGS=	INSTALL_PREFIX=${STAGEDIR}${PREFIX} \
		DATA_DIR=${STAGEDIR}${DATADIR} \
		DOCS_DIR=${STAGEDIR}${DOCSDIR} \
		ICON_DIR=${STAGEDIR}${PREFIX}/share/pixmaps \
		DESKTOP_DIR=${STAGEDIR}${PREFIX}/share/applications \
		MAN_DIR=${STAGEDIR}${PREFIX}/man/man1 \
		TW_DICPATH=${LOCALBASE}/share/hunspell \
		TW_HELPPATH=${DOCSDIR} \
		TW_PLUGINPATH=${PREFIX}/lib/texworks

VCS_REVISION=	1281
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DESKTOP_ENTRIES="TexWorks" \
		"Lowering the entry barrier to the TeX world" \
		"TeXworks" \
		"${PORTNAME}" \
		"Utility;Qt;" \
		true

PLIST_FILES=	bin/texworks \
		man/man1/texworks.1.gz \
		share/pixmaps/TeXworks.png
PLIST_DIRS=	lib/texworks
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1
PLIST_FILES+=	lib/texworks/libTWLuaPlugin.so
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	3
PLIST_FILES+=	lib/texworks/libTWPythonPlugin.so
.endif

post-patch:
	@${REINPLACE_CMD} -e '/zlib/d; s|COPYING ||' ${WRKSRC}/TeXworks.pro
	@${REINPLACE_CMD} -e 's|/usr/share|${LOCALBASE}/share|' \
		${WRKSRC}/src/TWUtils.cpp
	@${REINPLACE_CMD} -e 's|lua5.1|lua-5.1|' \
		${WRKSRC}/plugins-src/TWLuaPlugin/TWLuaPlugin.pro
	@${REINPLACE_CMD} -e '53,54s|^|#|; 57,59s|#||; s|python3|python-${PYTHON_VER}|' \
	    	${WRKSRC}/plugins-src/TWPythonPlugin/TWPythonPlugin.pro
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/INSTALLS/s|documentation manual ||' \
		${WRKSRC}/TeXworks.pro
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	    ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS} TeXworks.pro
.if ${PORT_OPTIONS:MLUA}
	cd ${WRKSRC}/plugins-src/TWLuaPlugin && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}/TWLuaPlugin.pro
.endif
.if ${PORT_OPTIONS:MPYTHON}
	cd ${WRKSRC}/plugins-src/TWPythonPlugin && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}/TWPythonPlugin.pro
.endif

post-build:
.if ${PORT_OPTIONS:MLUA}
	cd ${WRKSRC}/plugins-src/TWLuaPlugin && ${MAKE}
.endif
.if ${PORT_OPTIONS:MPYTHON}
	cd ${WRKSRC}/plugins-src/TWPythonPlugin && ${MAKE}
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/texworks
.if ${PORT_OPTIONS:MLUA}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/texworks
	${INSTALL_DATA} ${WRKSRC}/plugins-src/TWLuaPlugin/libTWLuaPlugin.so ${STAGEDIR}${PREFIX}/lib/texworks
.endif
.if ${PORT_OPTIONS:MPYTHON}
	${INSTALL_DATA} ${WRKSRC}/plugins-src/TWPythonPlugin/libTWPythonPlugin.so ${STAGEDIR}${PREFIX}/lib/texworks
.endif

.include <bsd.port.mk>
