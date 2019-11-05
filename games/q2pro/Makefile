# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	q2pro
PORTVERSION=	${SVN_REV}
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	LOCAL/alepulver

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II engine modification compatible with R1Q2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/gnu.txt

USES=		dos2unix gmake tar:bzip2
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	#

SVN_REV=	142

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S|${PREFIX}/||}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}
LDFLAGS_i386=	-Wl,-znotext

OPTIONS_DEFINE=		CLIENT DEDICATED GAME GL SOFT UI
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT=	CLIENT DEDICATED GL SOFT UI
OPTIONS_DEFAULT_i386=	ASM

CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAME_DESC=	Build main game (default mod)
GL_DESC=	Build OpenGL renderer
SOFT_DESC=	Build software renderer
UI_DESC=	Build user interface (for client menus)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USES+=		sdl
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
LIB_DEPENDS+=	libpng.so:graphics/png
USES+=		gl jpeg
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
	@${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		-e '/png_set_gray_1_2_4_to_8/s|png_set|&_expand|' \
			${WRKSRC}/ref_shared/r_images.c
	@${REINPLACE_CMD} -E 's|[[:digit:]]+|${SVN_REV}|' \
		${WRKSRC}/include/version.h

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
	${RM} -r q2pro

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.mk>
