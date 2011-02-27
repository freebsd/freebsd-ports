# New ports collection makefile for:	fteqw
# Date created:				2 Sep 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	fteqw
PORTVERSION=	3343
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Source/${PORTVERSION}
DISTNAME=	ftesrc${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QuakeWorld client with cool features, but still compatible

USE_DOS2UNIX=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	DEDICATED "Build dedicated server" on \
		GL "Build OpenGL (hardware) client" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL (software) client" on

SUB_FILES=	pkg-message

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DEDICATED) && defined(WITHOUT_GL) && defined(WITHOUT_SDL)
IGNORE=		needs at least one executable (DEDICATED, GL or SDL)
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	sv-rel
PLIST_FILES+=	bin/fteqw-sv
FTE_TARGETS+=	fteqw.sv
.endif

.if !defined(WITHOUT_GL) || !defined(WITHOUT_SDL)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITHOUT_GL)
USE_GL=		yes
ALL_TARGET+=	gl-rel
PLIST_FILES+=	bin/fteqw-gl
FTE_TARGETS+=	fteqw.gl
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=true
.endif

# SDL is used instead of the native X11 software version as it reports a
# memory allocation error at startup. It also fails with USEASM=true.
.if !defined(WITHOUT_SDL)
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
# Resolve name collision with jpeg-8 and API png14
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		-e 's|jpeg_mem_dest|local_jpeg_mem_dest|' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/client/image.c

do-install:
.for f in ${FTE_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/release/${f} ${PREFIX}/bin/${f:S/./-/}
.endfor

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
