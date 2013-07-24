# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	xconq
DISTVERSION=	7.5.0-0pre.0.20050612
CATEGORIES=	games tcl tk
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical multi-player strategy game and game design system

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	SDL

BROKEN=		Does not build

USE_BZIP2=	yes
USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-deprecated-writable-strings
CONFIGURE_ARGS=	--enable-alternate-scoresdir=${SCOREDIR} \
		--enable-alternate-gameuser=root \
		--enable-alternate-gamegroup=games
MAKE_ARGS=	GAMEPERM=2755 DIRPERM=775 FILEPERM=664
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	SCOREDIR="${SCOREDIR}"

MAN6=		xconq.6
INFO=		xconq

DESKTOP_ENTRIES="${PORTNAME}" "${COMMENT}" "" "${PORTNAME}" \
		"Game;StrategyGame;" false

SCOREDIR?=	/var/games/xconq

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
CONFIGURE_ARGS+=--enable-default-ui=sdl
PLIST_SUB+=	NOSDL="@comment "
.else
USE_XORG+=	xext xmu xt xaw
USE_TK_BUILD=	yes
USE_TK=		yes
CONFIGURE_ARGS+=--with-tclconfig=${TCL_LIBDIR} \
		--with-tkconfig=${TK_LIBDIR}
PLIST_SUB+=	NOSDL=""
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
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} xconq.info ${PREFIX}/${INFO_PATH})
	${STRIP_CMD} ${PREFIX}/bin/xconq
.if empty(PORT_OPTIONS:MSDL)
.for i in imf2x imfapp x2imf
	${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor
.endif
	@${FIND} ${DATADIR} -empty -delete

.include <bsd.port.mk>
