# New ports collection makefile for:	fteqw
# Date created:				2 Sep 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	fteqw
PORTVERSION=	2770
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	ftesrc${PORTVERSION}-all

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	QuakeWorld client with cool features, but still compatible

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GCC=	3.2+
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/engine

OPTIONS=	GL "Build OpenGL client" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SV "Build dedicated server" on \
		SW "Build software (X11) client" on \
		X86_ASM "Enable use of x86 assembly code" on

SUB_FILES=	pkg-message

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_DEDICATED) && defined(WITHOUT_GLX) && defined(WITHOUT_X11)
IGNORE=		needs at least one executable (DEDICATED, GLX or X11)
.endif

.if !defined(WITHOUT_GL) || !defined(WITHOUT_SW)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
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

.if !defined(WITHOUT_SV)
ALL_TARGET+=	sv-rel
PLIST_FILES+=	bin/fteqw-sv
FTE_TARGETS+=	fteqw.sv
.endif

.if !defined(WITHOUT_SW)
USE_XLIB=	yes
ALL_TARGET+=	sw-rel
PLIST_FILES+=	bin/fteqw-sw
FTE_TARGETS+=	fteqw.sw
.endif

.if !defined(WITHOUT_X86_ASM) && ${ARCH} == "i386"
MAKE_ENV+=	USEASM=true
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/malloc\.h/stdlib.h/' ${WRKSRC}/gl/gl_alias.c
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

.include <bsd.port.post.mk>
