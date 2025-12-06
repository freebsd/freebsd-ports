PORTNAME=	texworks
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.6.7
PORTREVISION=	9
CATEGORIES=	editors

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple TeX front-end program
WWW=		https://www.tug.org/texworks/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hunspell:textproc/hunspell
LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang cmake desktop-file-utils gl pkgconfig \
		qt:5 tex
USE_GITHUB=	yes
GH_ACCOUNT=	TeXworks
USE_QT=		buildtools:build designer:build qmake:build \
		core concurrent dbus declarative gui linguisttools \
		network script scripttools testlib uitools widgets xml
USE_GL=		gl
USE_TEX=	synctex
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DTeXworks_DIC_DIR:PATH=${LOCALBASE}/share/hunspell \
		-DTeXworks_DOCS_DIR:PATH=${DOCSDIR_REL} \
		-DTeXworks_HELP_DIR:PATH=${DOCSDIR_REL}

PORTDOCS=	*
PLIST_FILES=	bin/texworks \
		share/applications/texworks.desktop \
		share/icons/hicolor/128x128/apps/TeXworks.png \
		share/icons/hicolor/48x48/apps/TeXworks.png \
		share/icons/hicolor/512x512/apps/TeXworks.png \
		share/icons/hicolor/64x64/apps/TeXworks.png \
		share/man/man1/texworks.1.gz \
		share/metainfo/texworks.appdata.xml

OPTIONS_DEFINE=	DOCS LUA PYTHON

LUA_USES=		lua
LUA_CMAKE_BOOL=		WITH_LUA
LUA_PLIST_FILES=	lib/texworks/libTWLuaPlugin.so

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_PLIST_FILES=	lib/texworks/libTWPythonPlugin.so

.include <bsd.port.mk>
