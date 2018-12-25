# Created by: Diego Depaoli <trebestie@gmail.com>
# $FreeBSD$

PORTNAME=	texworks
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.6.2
CATEGORIES=	editors

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple TeX front-end program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hunspell:textproc/hunspell
LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		cmake desktop-file-utils pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	TeXworks
USE_QT=		buildtools_build designer_build qmake_build \
		core concurrent dbus gui linguisttools script \
		scripttools uitools widgets xml

USE_TEX=	synctex
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DTeXworks_DIC_DIR:PATH=${LOCALBASE}/share/hunspell \
		-DTeXworks_DOCS_DIR:PATH=${DOCSDIR_REL} \
		-DTeXworks_HELP_DIR:PATH=${DOCSDIR_REL} \
		-DTeXworks_MAN_DIR:PATH=man/man1

PORTDOCS=	*
PLIST_FILES=	bin/texworks \
		man/man1/texworks.1.gz \
		share/appdata/texworks.appdata.xml \
		share/applications/texworks.desktop \
		share/pixmaps/TeXworks.png

OPTIONS_DEFINE=	DOCS LUA PYTHON

LUA_USES=		lua
LUA_CMAKE_BOOL=		WITH_LUA
LUA_PLIST_FILES=	lib/texworks/libTWLuaPlugin.so

PYTHON_USES=		python:3.4+
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_PLIST_FILES=	lib/texworks/libTWPythonPlugin.so

.include <bsd.port.mk>
