# New ports collection makefile for:	q2pro
# Date created:				2006-12-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	q2pro
PORTVERSION=	${SVN_REV}
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alepulver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake II engine modification compatible with R1Q2

USE_BZIP2=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	#

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		GAME "Build a main game .so file" off \
		GL "Build OpenGL render" on \
		SOFT "Build software render" on \
		UI "Build user interface (for CLIENT menus)" on \
		X86_ASM "Enable use of optimized x86 assembly code" on

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

SVN_REV=	142
LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED)
IGNORE=		needs at least one executable (CLIENT and DEDICATED)
.endif

.if !defined(WITHOUT_CLIENT)
USE_SDL+=	sdl
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
ALL_TARGET+=	server
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAME)
ALL_TARGET+=	game
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if !defined(WITHOUT_GL)
USE_GL=		yes
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png
ALL_TARGET+=	ref_newgl
PLIST_SUB+=	GL=""
.else
PLIST_SUB+=	GL="@comment "
.endif

.if !defined(WITHOUT_SOFT)
ALL_TARGET+=	ref_soft
PLIST_SUB+=	SOFT=""
.else
PLIST_SUB+=	SOFT="@comment "
.endif

.if !defined(WITHOUT_UI)
ALL_TARGET+=	ui
PLIST_SUB+=	UI=""
.else
PLIST_SUB+=	UI="@comment "
.endif

.if !defined(WITHOUT_X86_ASM) && ${ARCH} == "i386"
MAKE_ENV+=	USE_X86_ASM=yes
.endif

post-patch:
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_shared/r_images.c

do-install:
	${MKDIR} ${LIBDIR}/baseq2
.if !defined(WITHOUT_CLIENT)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/q2pro ${PREFIX}/bin
.endif
.if !defined(WITHOUT_DEDICATED)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/q2proded ${PREFIX}/bin
.endif
.if defined(WITH_GAME)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/game.so ${LIBDIR}/baseq2
.endif
.if !defined(WITHOUT_GL)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/ref_newgl.so ${LIBDIR}
.endif
.if !defined(WITHOUT_SOFT)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/ref_soft.so ${LIBDIR}
.endif
.if !defined(WITHOUT_UI)
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/ui.so ${LIBDIR}
.endif

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r${SVN_REV} \
		https://svn.sourceforge.net/svnroot/q2pro/q2pro q2pro
	${TAR} jcf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} q2pro
	${RM} -rf q2pro

.include <bsd.port.post.mk>
