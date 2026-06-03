PORTNAME=	texworks
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.6.11
CATEGORIES=	editors

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Simple TeX front-end program
WWW=		https://www.tug.org/texworks/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hunspell:textproc/hunspell
LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libpoppler-qt6.so:graphics/poppler-qt6 \
		libpoppler.so:graphics/poppler

USES=		cmake compiler:c++11-lang desktop-file-utils gl pkgconfig qt:6 \
		tex
USE_GITHUB=	yes
GH_ACCOUNT=	TeXworks
USE_GL=		opengl
USE_LDCONFIG=	yes
USE_QT=		5compat base declarative tools
USE_TEX=	synctex

CMAKE_ARGS=	-DTeXworks_DIC_DIR:PATH=${LOCALBASE}/share/hunspell \
		-DTeXworks_DOCS_DIR:PATH=${DOCSDIR_REL} \
		-DTeXworks_HELP_DIR:PATH=${DOCSDIR_REL}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LUA PYTHON
OPTIONS_SUB=	yes

LUA_USES=		lua
LUA_CMAKE_BOOL=		WITH_LUA
PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	WITH_PYTHON

.include <bsd.port.mk>
