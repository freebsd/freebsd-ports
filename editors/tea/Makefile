PORTNAME=	tea
PORTVERSION=	63.3.1
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Simple and powerful Qt-based text editor
WWW=		https://tea.ourproject.org/

LICENSE=	GPLv3

USES=		cmake desktop-file-utils gl localbase:ldflags pkgconfig:build qt:6

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		SPELL
OPTIONS_GROUP_SPELL=	ASPELL HUNSPELL
OPTIONS_DEFAULT=	ASPELL HUNSPELL
SPELL_DESC=		Spell checker backend

USE_QT=		base
USE_GL=		opengl
USE_LOCALE=	en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	psemiletov
GH_PROJECT=	${PORTNAME}-qt

CMAKE_ARGS+=	-DUSE_PRINTER=ON

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CMAKE_BOOL=	USE_ASPELL

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_CMAKE_BOOL=	USE_HUNSPELL

post-install:
	(cd ${WRKSRC}/manuals \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
