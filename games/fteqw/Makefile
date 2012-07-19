# New ports collection makefile for:	fteqw
# Date created:				2 Sep 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	fteqw
PORTVERSION=	3343
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Source/${PORTVERSION}
DISTNAME=	ftesrc${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QuakeWorld client with cool features, but still compatible

USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_CSTD=	gnu89
NO_WRKSUBDIR=	yes

OPTIONS_MULTI=	EXE
OPTIONS_MULTI_EXE=	DEDICATED OPENGL SDL
OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	DEDICATED OPENGL OPTIMIZED_CFLAGS SDL
DEDICATED_DESC=	Build dedicated server

SUB_FILES=	pkg-message

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	sv-rel
PLIST_FILES+=	bin/fteqw-sv
FTE_TARGETS+=	fteqw.sv
.endif

.if ${PORT_OPTIONS:MGL} || !empty(PORT_OPTIONS:MSDL)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis
CFLAGS+=	-I${LOCALBASE}/include/libpng15
.endif

.if ${PORT_OPTIONS:MGL}
USE_GL=		yes
ALL_TARGET+=	gl-rel
PLIST_FILES+=	bin/fteqw-gl
FTE_TARGETS+=	fteqw.gl
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZED_CFLAGS=true
.endif

# SDL is used instead of the native X11 software version as it reports a
# memory allocation error at startup. It also fails with USEASM=true.
.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
ALL_TARGET+=	sw-rel
PLIST_FILES+=	bin/fteqw-sdl
FTE_TARGETS+=	fteqw.sdl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/alloca\.h/stdlib.h/' \
		${WRKSRC}/gl/gl_alias.c ${WRKSRC}/common/com_mesh.c
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' \
		${WRKSRC}/common/plugin.c ${WRKSRC}/server/svq3_game.c

do-install:
.for f in ${FTE_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/release/${f} ${PREFIX}/bin/${f:S/./-/}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
