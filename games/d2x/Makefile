# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	d2x
PORTVERSION=	0.2.5
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/d2x/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix port of Descent 2 Game

GNU_CONFIGURE=	yes
USES=		gmake sdl
USE_SDL=	sdl image

CONFIGURE_ARGS=	--disable-network --disable-debug

PORTDOCS=	README TODO NEWS AUTHORS readme.txt installation.txt
PLIST_FILES=	bin/d2x

OPTIONS_DEFINE=	OPENGL DOCS

OPENGL_CONFIGURE_WITH=	opengl
OPENGL_CXXFLAGS=	-I${LOCALBASE}/include
OPENGL_LDFLAGS=		-L${LOCALBASE}/lib
OPENGL_USE=	GL=glut

post-install-OPENGL-on:
	${MV} ${STAGEDIR}${PREFIX}/bin/d2x-gl  ${STAGEDIR}${PREFIX}/bin/d2x

post-install-OPENGL-off:
	${MV} ${STAGEDIR}${PREFIX}/bin/d2x-sdl  ${STAGEDIR}${PREFIX}/bin/d2x

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
