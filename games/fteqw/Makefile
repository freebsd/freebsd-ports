# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fteqw
PORTVERSION=	3343
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Source/${PORTVERSION}
DISTNAME=	ftesrc${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QuakeWorld client with cool features, but still compatible

USES=		gmake dos2unix
USE_CSTD=	gnu89
NO_WRKSUBDIR=	yes
MAKE_ARGS+=	FTE_TARGET=bsd

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	GLCLIENT SDLCLIENT SERVER
OPTIONS_DEFAULT=	GLCLIENT SDLCLIENT SERVER OPTIMIZED_CFLAGS

FLAVOR_DESC=	Clients and servers
GLCLIENT_DESC=	Build OpenGL client
SDLCLIENT_DESC=	Build SDL client
SERVER_DESC=	Build dedicated server

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER}
ALL_TARGET+=	sv-rel
PLIST_FILES+=	bin/fteqw-sv
.endif

.if ${PORT_OPTIONS:MGLCLIENT} || !empty(PORT_OPTIONS:MSDLCLIENT)
LIB_DEPENDS+=	libpng.so:graphics/png \
		libvorbis.so:audio/libvorbis
USES+=		jpeg
.endif

.if ${PORT_OPTIONS:MGLCLIENT}
USE_GL=		gl
ALL_TARGET+=	gl-rel
PLIST_FILES+=	bin/fteqw-gl
.endif

# SDL is used instead of the native X11 software version as it reports a
# memory allocation error at startup.  It also fails with USEASM=true.
.if ${PORT_OPTIONS:MSDLCLIENT}
USE_SDL=	sdl
ALL_TARGET+=	sw-rel
PLIST_FILES+=	bin/fteqw-sdl
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZED_CFLAGS=true
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/alloca\.h/stdlib.h/' \
		${WRKSRC}/gl/gl_alias.c ${WRKSRC}/common/com_mesh.c
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' \
		${WRKSRC}/common/plugin.c ${WRKSRC}/server/svq3_game.c

do-install:
.for f in ${PLIST_FILES:T}
	${INSTALL_PROGRAM} ${WRKSRC}/release/${f:S/-/./} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.mk>
