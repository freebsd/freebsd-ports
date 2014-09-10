# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdlskk
PORTVERSION=	0.5
PORTREVISION=	3
CATEGORIES=	devel graphics ruby
MASTER_SITES=	http://www.kmc.gr.jp/~ohai/sdlskk/
DIST_SUBDIR=	ruby

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	SKK like library for input Japanese, based on SDL

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		iconv libtool
USE_SDL=	image ttf sdl
USE_LDCONFIG=   yes

PLIST_FILES=	include/SDL/sdlskk.h \
		lib/libSDLSKK.a \
		lib/libSDLSKK.so \
		lib/libSDLSKK.so.2 \
		lib/libSDLSKK.so.2.0.0

PORTDOCS=	AUTHORS NEWS README README.ja

OPTIONS_DEFINE= DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
