# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	q2pro
PORTVERSION=	${SVN_REV}
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake II engine modification compatible with R1Q2

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/gnu.txt

USES=		dos2unix gmake tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	#

SVN_REV=	142

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S|${PREFIX}/||}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=		GAME GL SOFT UI
OPTIONS_DEFINE_i386=	ASM
OPTIONS_MULTI=		FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT DEDICATED GL SOFT UI
OPTIONS_DEFAULT_I386=	ASM

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build main game (default mod)
GL_DESC=	Build OpenGL render
SOFT_DESC=	Build software render
UI_DESC=	Build user interface (for client menus)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_SDL+=	sdl
ALL_TARGET+=	client
PLIST_SUB+=	CLIENT=""
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
ALL_TARGET+=	server
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAME}
ALL_TARGET+=	game
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if ${PORT_OPTIONS:MGL}
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng.so:${PORTSDIR}/graphics/png
USE_GL=		gl
ALL_TARGET+=	ref_newgl
PLIST_SUB+=	GL=""
.else
PLIST_SUB+=	GL="@comment "
.endif

.if ${PORT_OPTIONS:MSOFT}
ALL_TARGET+=	ref_soft
PLIST_SUB+=	SOFT=""
.else
PLIST_SUB+=	SOFT="@comment "
.endif

.if ${PORT_OPTIONS:MUI}
ALL_TARGET+=	ui
PLIST_SUB+=	UI=""
.else
PLIST_SUB+=	UI="@comment "
.endif

.if ${PORT_OPTIONS:MASM}
MAKE_ENV+=	USE_X86_ASM=yes
.endif

post-patch:
# Resolve name collision with jpeg-8
	@${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_shared/r_images.c

do-install:
	@${MKDIR} ${STAGEDIR}${LIBDIR}/baseq2
.if ${PORT_OPTIONS:MCLIENT}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/q2pro \
		${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MDEDICATED}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/q2proded \
		${STAGEDIR}${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MGAME}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/game.so \
		${STAGEDIR}${LIBDIR}/baseq2
.endif
.if ${PORT_OPTIONS:MGL}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/ref_newgl.so \
		${STAGEDIR}${LIBDIR}
.endif
.if ${PORT_OPTIONS:MSOFT}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/ref_soft.so \
		${STAGEDIR}${LIBDIR}
.endif
.if ${PORT_OPTIONS:MUI}
	${INSTALL_PROGRAM} ${WRKSRC}/build/release/ui.so \
		${STAGEDIR}${LIBDIR}
.endif

generate-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export -r${SVN_REV} \
		https://svn.sourceforge.net/svnroot/q2pro/q2pro q2pro
	${TAR} jcf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} q2pro
	${RM} -rf q2pro

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
