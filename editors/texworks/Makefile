# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	texworks
PORTVERSION=	0.4.6
DISTVERSIONPREFIX=	release-
PORTREVISION=	6
CATEGORIES=	editors

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple TeX front-end program

LICENSE=	GPLv2

BUILD_DEPENDS=	hunspell:textproc/hunspell
LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4

USES=		pkgconfig qmake
USE_GITHUB=	yes
GH_ACCOUNT=	TeXworks
USE_QT4=	gui corelib rcc_build moc_build uic_build \
		dbus xml scripttools designer_build
QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX} \
		DATA_DIR=${DATADIR} \
		DOCS_DIR=${DOCSDIR} \
		ICON_DIR=${PREFIX}/share/pixmaps \
		DESKTOP_DIR=${PREFIX}/share/applications \
		MAN_DIR=${PREFIX}/man/man1 \
		TW_DICPATH=${LOCALBASE}/share/hunspell \
		TW_HELPPATH=${DOCSDIR} \
		TW_PLUGINPATH=${PREFIX}/lib/texworks
USE_TEX=	synctex

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

OPTIONS_DEFINE=	DOCS LUA PYTHON
LUA_USES=	lua:51
LUA_PLIST_FILES=lib/texworks/libTWLuaPlugin.so
PYTHON_USES=	python:3.4+
PYTHON_PLIST_FILES=lib/texworks/libTWPythonPlugin.so

post-extract:
	cd ${WRKSRC} && ${INSTALL_DATA} GitArchiveInfo.txt src/GitRev.h

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/share,${LOCALBASE}/share,' \
	    ${WRKSRC}/src/TWUtils.cpp
	@${REINPLACE_CMD} -e 's,lua5.1,lua-5.1,' \
	    ${WRKSRC}/plugins-src/TWLuaPlugin/TWLuaPlugin.pro
	@${REINPLACE_CMD} -e '53,54s,^,#,' \
	    -e '57,59s,#,,' \
	    -e 's,python3,python-${PYTHON_VER},' \
	    ${WRKSRC}/plugins-src/TWPythonPlugin/TWPythonPlugin.pro

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e '/INSTALLS/s,documentation manual ,,' \
	    ${WRKSRC}/TeXworks.pro

post-configure-LUA-on:
	cd ${WRKSRC}/plugins-src/TWLuaPlugin && ${SETENV} ${CONFIGURE_ENV} \
	    ${QMAKE} ${QMAKE_ARGS}

post-configure-PYTHON-on:
	cd ${WRKSRC}/plugins-src/TWPythonPlugin && ${SETENV} ${CONFIGURE_ENV} \
	    ${QMAKE} ${QMAKE_ARGS}

post-build-LUA-on:
	cd ${WRKSRC}/plugins-src/TWLuaPlugin && ${MAKE}

post-build-PYTHON-on:
	cd ${WRKSRC}/plugins-src/TWPythonPlugin && ${MAKE}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/texworks

post-install-LUA-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/texworks
	cd ${WRKSRC}/plugins-src/TWLuaPlugin && \
	    ${INSTALL_DATA} libTWLuaPlugin.so \
		${STAGEDIR}${PREFIX}/lib/texworks

post-install-PYTHON-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/texworks
	cd ${WRKSRC}/plugins-src/TWPythonPlugin && \
	    ${INSTALL_DATA} libTWPythonPlugin.so \
		${STAGEDIR}${PREFIX}/lib/texworks

.include <bsd.port.mk>
