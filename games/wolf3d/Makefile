# New ports collection makefile for:	wolf3d
# Date created:			13 Jan 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	wolf3d
PORTVERSION=	20011028
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.icculus.org/wolf3d/:wolf \
		http://cvsup.theplanet.com/distfiles/:wolf \
		http://www.liquidx.org/distfiles/:sw
DISTNAME=	wolf3d-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:wolf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Wolfenstein 3D Linux" by Steven Fuller (1992)

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-10-20

USE_SDL=	sdl

OPTIONS_DEFINE=	WOLF_SW OPTIMIZED_CFLAGS SPEAR_SW DOCS
OPTIONS_DEFAULT=	WOLF_SW OPTIMIZED_CFLAGS
WOLF_SW_DESC=	Install shareware data for Wolfenstein 3D
SPEAR_SW_DESC=	Install shareware data for Spear of Destiny

SUB_FILES=	pkg-message wolf3d

WOLF_BIN=	sdlwolf3d
WOLF_VERS=	wf ws sf ss

WF_CF=		-DWMODE=1
WS_CF=		-DWMODE=0
SF_CF=		-DWMODE=3
SS_CF=		-DWMODE=2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWOLF_SW}
DISTFILES+=	wolfdata${EXTRACT_SUFX}:sw
PLIST_SUB+=	WOLF_SW=""
.else
PLIST_SUB+=	WOLF_SW="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPT_CF="-O2 -fomit-frame-pointer -ffast-math -funroll-loops"
.endif

.if ${PORT_OPTIONS:MSPEAR_SW}
DISTFILES+=	speardata${EXTRACT_SUFX}:sw
PLIST_SUB+=	SPEAR_SW=""
.else
PLIST_SUB+=	SPEAR_SW="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MSPEAR_SW}
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
.if ${PORT_OPTIONS:MWOLF_SW}
	${INSTALL_DATA} ${WRKDIR}/wolfdata/* ${DATADIR}
.endif
.if ${PORT_OPTIONS:MSPEAR_SW}
	${INSTALL_DATA} ${WRKDIR}/*.sdm ${DATADIR}
.endif

.if ${PORT_OPTIONS:MDOCS}
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

.include <bsd.port.mk>
