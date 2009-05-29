# New ports collection makefile for:	wolf3d
# Date created:			13 Jan 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	wolf3d
PORTVERSION=	20011028
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/wolf3d/:wolf \
		http://cvsup.theplanet.com/distfiles/:wolf \
		http://www.liquidx.org/distfiles/:sw
DISTNAME=	wolf3d-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:wolf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Wolfenstein 3D Linux" by Steven Fuller (1992)

USE_SDL=	sdl

OPTIONS=	WOLF_SW "Install shareware data for Wolfenstein 3D" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SPEAR_SW "Install shareware data for Spear of Destiny" off

SUB_FILES=	pkg-message wolf3d

WOLF_BIN=	sdlwolf3d
WOLF_VERS=	wf ws sf ss

WF_CF=		-DWMODE=1
WS_CF=		-DWMODE=0
SF_CF=		-DWMODE=3
SS_CF=		-DWMODE=2

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WOLF_SW)
DISTFILES+=	wolfdata${EXTRACT_SUFX}:sw
PLIST_SUB+=	WOLF_SW=""
.else
PLIST_SUB+=	WOLF_SW="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPT_CF="-O2 -fomit-frame-pointer -ffast-math -funroll-loops"
.endif

.if defined(WITH_SPEAR_SW)
DISTFILES+=	speardata${EXTRACT_SUFX}:sw
PLIST_SUB+=	SPEAR_SW=""
.else
PLIST_SUB+=	SPEAR_SW="@comment "
.endif

post-extract:
.if defined(WITH_SPEAR_SW)
	@${MV} ${WRKDIR}/audit.sdm ${WRKDIR}/audiot.sdm
.endif

do-build:
.for f in ${WOLF_VERS}
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} WF=${${f:U}_CF} ${ALL_TARGET}
	@cd ${WRKSRC} && ${MV} ${WOLF_BIN} ${WOLF_BIN}-${f}
	@cd ${WRKSRC}; ${MAKE} clean
.endfor

do-install:
	${MKDIR} ${PREFIX}/libexec/wolf3d
.for f in ${WOLF_VERS}
	${INSTALL_PROGRAM} ${WRKSRC}/${WOLF_BIN}-${f} ${PREFIX}/libexec/wolf3d
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/wolf3d ${PREFIX}/bin/wolf3d

	${MKDIR} ${DATADIR}
.if !defined(WITHOUT_WOLF_SW)
	${INSTALL_DATA} ${WRKDIR}/wolfdata/* ${DATADIR}
.endif
.if defined(WITH_SPEAR_SW)
	${INSTALL_DATA} ${WRKDIR}/*.sdm ${DATADIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}/docs
.   for f in IDEAS NOTES README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
