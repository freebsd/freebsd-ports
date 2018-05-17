# Created by: Ronald Kuehn <rk@ronald.org>
# $FreeBSD$

PORTNAME=	imaze
PORTVERSION=	1.4
PORTREVISION=	5
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

OPTIONS_DEFINE=	AUDIO DOCS JOYSTICK
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

post-patch:
	@${REINPLACE_CMD} 's@ninja@imazeninja@g' ${WRKSRC}/man6/*.6

do-install:
	cd ${WRKSRC}/source && ${INSTALL_PROGRAM} \
		genlab imaze imazesrv imazestat xlabed \
		${STAGEDIR}${PREFIX}/bin
# Install ninja as imazeninja to resolve conflict with devel/ninja
	${INSTALL_PROGRAM} ${WRKSRC}/source/ninja ${STAGEDIR}${PREFIX}/bin/imazeninja
	cd ${WRKSRC}/man6 && ${INSTALL_MAN} \
		genlab.6 imaze.6 imazesrv.6 imazestat.6 xlabed.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6
	${INSTALL_MAN} ${WRKSRC}/man6/ninja.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6/imazeninja.6
	@${MKDIR} ${STAGEDIR}${DATADIR}/labs
	${INSTALL_DATA} ${WRKSRC}/labs/*.lab ${STAGEDIR}${DATADIR}/labs
	@${MKDIR} ${STAGEDIR}${DATADIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/sounds/*.au ${STAGEDIR}${DATADIR}/sounds

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
