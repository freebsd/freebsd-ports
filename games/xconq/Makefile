# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	xconq
DISTVERSION=	7.5.0-0pre.0.20050612
PORTREVISION=	2
CATEGORIES=	games tcl tk
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical multi-player strategy game and game design system

LICENSE=	GPLv2+

OPTIONS_DEFINE=	SDL

USES=		compiler gmake makeinfo tar:bzip2 xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-alternate-scoresdir=${SCOREDIR} \
		--enable-alternate-gameuser=root \
		--enable-alternate-gamegroup=games
CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
MAKE_ARGS=	GAMEPERM=755 DIRPERM=775 FILEPERM=664
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	SCOREDIR="${SCOREDIR}"

INFO=		xconq

DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "" "${PORTNAME}" \
		"Game;StrategyGame;" false

SCOREDIR?=	/var/games/xconq

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USES+=		sdl
USE_SDL=	sdl
CONFIGURE_ARGS+=--enable-default-ui=sdl
PLIST_SUB+=	NOSDL="@comment "
.else
USES+=		tk
USE_XORG+=	xext xmu xt xaw
CONFIGURE_ARGS+=--with-tclconfig=${TCL_LIBDIR} \
		--with-tkconfig=${TK_LIBDIR}
PLIST_SUB+=	NOSDL=""
.endif

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-deprecated-writable-strings
.else
CFLAGS+=	-Wno-write-strings
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^HFLAGS/s| $${debugging}||' ${WRKSRC}/configure
# Fix for gmake >= 3.82
	@${FIND} ${WRKSRC} -name Makefile.in -print | ${XARGS} \
		${REINPLACE_CMD} -e 's/^   */	/'

post-build:
	(cd ${WRKSRC}/doc && makeinfo xconq.texi)

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xconq.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xconq
.if empty(PORT_OPTIONS:MSDL)
.for i in imf2x imfapp x2imf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
.endif
	@${FIND} ${STAGEDIR}${DATADIR} -empty -delete
	@${MKDIR} ${STAGEDIR}${SCOREDIR}

.include <bsd.port.post.mk>
