# Created by: Ronald Kuehn <rk@ronald.org>
# $FreeBSD$

PORTNAME=	imaze
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.sourcefiles.org/Games/Arcade/
PKGNAMESUFFIX=	-${TOOLKIT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player network action game for TCP/IP with 3D graphics

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright

USE_XORG=	x11 xaw xmu xt

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${TOOLKIT} X11Dir="${LOCALBASE}" CFlags="${CFLAGS}"
MAKE_ENV=	SOUNDDIR="${DATADIR}/sounds"

BUILD_WRKSRC=	${WRKSRC}/source
CONFIGURE_WRKSRC=	${WRKSRC}/source

OPTIONS_DEFINE=	AUDIO JOYSTICK
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	ATHENA MOTIF XVIEW
OPTIONS_DEFAULT=	ATHENA AUDIO JOYSTICK

ATHENA_DESC=	Athena widget library support
AUDIO_DESC=	Audio support
JOYSTICK_DESC=	Joystick support
XVIEW_DESC=	XView widget library support

ATHENA_VARS=	TOOLKIT=athena
AUDIO_CONFIGURE_OFF=	noaudio
JOYSTICK_CONFIGURE_OFF=	nojoystick
MOTIF_USES=	motif
MOTIF_VARS=	MOTIFLIB="-L${LOCALBASE}/lib -lXm -lXt" TOOLKIT=motif
XVIEW_LIB_DEPENDS=	libxview.so:x11-toolkits/xview
XVIEW_VARS=	TOOLKIT=xview

do-install:
.for i in genlab imaze imazesrv imazestat ninja xlabed
	(cd ${WRKSRC}/source && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor
	(cd ${WRKSRC}/man6 && ${INSTALL_MAN} *.6 ${STAGEDIR}${MAN6PREFIX}/man/man6)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DATADIR}/labs
	(cd ${WRKSRC}/labs && ${INSTALL_DATA} *.lab ${STAGEDIR}${DATADIR}/labs)
	@${MKDIR} ${STAGEDIR}${DATADIR}/sounds
	(cd ${WRKSRC}/sounds && ${INSTALL_DATA} *.au ${STAGEDIR}${DATADIR}/sounds)
	@${ECHO_MSG} "Please read the file \"${DATADIR}/README\"."

.include <bsd.port.mk>
