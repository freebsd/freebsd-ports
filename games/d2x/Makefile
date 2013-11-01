# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	d2x
PORTVERSION=	0.2.5
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://offload2.icculus.org:9090/d2x/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix port of Descent 2 Game

GNU_CONFIGURE=	yes
USES=		gmake
USE_SDL=	sdl image

CONFIGURE_ARGS=	--disable-network --disable-debug

PORTDOCS=	README TODO NEWS AUTHORS readme.txt installation.txt
PLIST_FILES=	bin/d2x

OPTIONS_DEFINE=	OPENGL DOCS

OPENGL_CONFIGURE_WITH=	opengl
OPENGL_CXXFLAGS=	-I${LOCALBASE}/include
OPENGL_LDFLAGS=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		glut
.endif

do-install:
.if ${PORT_OPTIONS:MOPENGL}
		${INSTALL_PROGRAM} ${WRKSRC}/d2x-gl  ${STAGEDIR}${PREFIX}/bin/d2x
.else
		${INSTALL_PROGRAM} ${WRKSRC}/d2x-sdl ${STAGEDIR}${PREFIX}/bin/d2x
.endif
	        @${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	        ${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
