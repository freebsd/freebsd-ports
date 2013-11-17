# Created by: Ronald Kuehn <rk@ronald.org>
# $FreeBSD$

PORTNAME=	imaze
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	TUCOWS/x11/entertain/ \
		http://www.sourcefiles.org/Games/Arcade/
PKGNAMESUFFIX=	-${TOOLKIT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player network action game for TCP/IP with 3D graphics

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/Copyright

OPTIONS_DEFINE=	AUDIO JOYSTICK
OPTIONS_RADIO=	GUI
OPTIONS_RADIO_GUI=	XVIEW MOTIF
OPTIONS_DEFAULT=	AUDIO JOYSTICK XVIEW
AUDIO_DESC=	Audio support
JOYSTICK_DESC=	Joystick support
XVIEW_DESC=	XView widget library support

CONFIGURE_WRKSRC=${WRKSRC}/source
BUILD_WRKSRC=	${WRKSRC}/source

USE_XORG=	x11 xaw xt
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${TOOLKIT} X11Dir="${LOCALBASE}" CFlags="${CFLAGS}"
MAKE_ENV=	SOUNDDIR="${DATADIR}/sounds"

MAN_PAGES=	genlab.6 imaze.6 imazesrv.6 imazestat.6 ninja.6 xlabed.6

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MAUDIO)
CONFIGURE_ARGS+=noaudio
.endif

.if empty(PORT_OPTIONS:MJOYSTICK)
CONFIGURE_ARGS+=nojoystick
.endif

.if empty(PORT_OPTIONS:MMOTIF) && empty(PORT_OPTIONS:MXVIEW)
TOOLKIT=	athena
.endif

.if ${PORT_OPTIONS:MMOTIF}
USES+=		motif
TOOLKIT=	motif
.endif

.if ${PORT_OPTIONS:MXVIEW}
LIB_DEPENDS+=	xview:${PORTSDIR}/x11-toolkits/xview
TOOLKIT=	xview
.endif

do-install:
.for i in genlab imaze imazesrv imazestat ninja xlabed
	(cd ${WRKSRC}/source && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor
.for i in ${MAN_PAGES}
	(cd ${WRKSRC}/man6 && ${INSTALL_MAN} ${i} ${STAGEDIR}${MAN6PREFIX}/man/man6)
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/labs
	(cd ${WRKSRC}/labs && ${INSTALL_DATA} *.lab ${STAGEDIR}${DATADIR}/labs)
	@${MKDIR} ${STAGEDIR}${DATADIR}/sounds
	(cd ${WRKSRC}/sounds && ${INSTALL_DATA} *.au ${STAGEDIR}${DATADIR}/sounds)
	@${ECHO_MSG} "Please read the file \"${DATADIR}/README\"."

.include <bsd.port.mk>
