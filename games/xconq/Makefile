PORTNAME=	xconq
DISTVERSION=	7.5.0-0pre.0.20050612
PORTREVISION=	3
CATEGORIES=	games tcl tk
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical multi-player strategy game and game design system
WWW=		https://xconq.sourceforge.net/

LICENSE=	GPLv2+

USES=		compiler gmake tar:bzip2 xorg
USE_CXXSTD=	c++14
USE_XORG=	x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-alternate-scoresdir=${SCOREDIR} \
		--enable-alternate-gameuser=root \
		--enable-alternate-gamegroup=games

MAKE_ARGS=	GAMEPERM=755 DIRPERM=775 FILEPERM=664
MAKE_JOBS_UNSAFE=	yes

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "" "${PORTNAME}" \
		"Game;StrategyGame;" false

INFO=		xconq
PLIST_SUB=	SCOREDIR="${SCOREDIR}"

OPTIONS_DEFINE=	SDL INFO
OPTIONS_DEFAULT=	INFO

INFO_USES=		makeinfo
SDL_USES=		sdl
SDL_USES_OFF=	tk xorg
SDL_USE=	SDL=sdl
SDL_USE_OFF=	XORG=xext,xmu,xt,xaw
SDL_CONFIGURE_ON=--enable-default-ui=sdl
SDL_CONFIGURE_OFF=--with-tclconfig=${TCL_LIBDIR} \
		--with-tkconfig=${TK_LIBDIR}
SDL_PLIST_SUB=	NOSDL="@comment "
SDL_PLIST_SUB_OFF=	NOSDL=""

SCOREDIR?=	/var/games/xconq

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-deprecated-writable-strings
.else
CFLAGS+=	-Wno-write-strings
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^HFLAGS/s| $${debugging}||' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in -print | ${XARGS} \
		${REINPLACE_CMD} -e 's/^   */	/'

post-build-INFO-on:
	(cd ${WRKSRC}/doc && makeinfo xconq.texi)

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xconq.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xconq
	@${FIND} ${STAGEDIR}${DATADIR} -empty -delete
	@${MKDIR} ${STAGEDIR}${SCOREDIR}

post-install-SDL-off:
.for i in imf2x imfapp x2imf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

.include <bsd.port.post.mk>
