# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdlskk
PORTVERSION=	0.5
CATEGORIES=	devel graphics ruby
MASTER_SITES=	http://www.kmc.gr.jp/~ohai/sdlskk/
DIST_SUBDIR=	ruby

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	SKK on SDL

LICENSE=	LGPL21

USES=		iconv
USE_SDL=	image ttf sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=   yes

PLIST_FILES=	include/SDL/sdlskk.h \
		lib/libSDLSKK.a \
		lib/libSDLSKK.la \
		lib/libSDLSKK.so.2.0
PLIST_DIRSTRY=	include/SDL

PORTDOCS=	AUTHORS NEWS README README.ja

OPTIONS_DEFINE= DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
