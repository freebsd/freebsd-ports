# New ports collection makefile for:    imaze
# Date created:         27. April 1996
# Whom:                 Ronald Kuehn <rk@ronald.org>
#
# $FreeBSD$
#

PORTNAME=	imaze
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://home.tu-clausthal.de/student/iMaze/files/
PKGNAMESUFFIX=	-${TOOLKIT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-player network action game for TCP/IP with 3D graphics

.if defined(WITH_MOTIF) && defined(HAVE_MOTIF)
USE_MOTIF=	yes
TOOLKIT=	motif
.elif defined(WITH_ATHENA)
TOOLKIT=	athena
USE_XORG+=	xaw
.else
LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview
TOOLKIT=	xview
USE_XORG+=	xaw
.endif

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	${TOOLKIT} X11Dir=${LOCALBASE} CFlags="${CFLAGS}"
CONFIGURE_WRKSRC=${WRKSRC}/source
BUILD_WRKSRC=	${WRKSRC}/source
MAKE_ENV=	SOUNDDIR=${SOUNDDIR}
MAN6=		genlab.6 imaze.6 imazesrv.6 imazestat.6 ninja.6 xlabed.6
MANCOMPRESSED=	no
USE_XORG+=	x11 xt

.if defined(WITHOUT_AUDIO)
CONFIGURE_ARGS+=noaudio
.endif
.if defined(WITHOUT_JOYSTICK)
CONFIGURE_ARGS+=nojoystick
.endif

PROGRAMS=	imaze imazesrv imazestat ninja genlab xlabed
SOUNDDIR=	${PREFIX}/share/imaze/sounds

pre-everything::
	@$(ECHO_MSG) "iMaze can be built with XView (default), Motif or" \
		"Athena widgets."
	@$(ECHO_MSG) "Use \"-DWITH_MOTIF\" or \"-DWITH_ATHENA\" to select" \
		"Motif or Athena widgets."
	@$(ECHO_MSG) "Audio and joystick support can be disabled with" \
		"\"-DWITHOUT_AUDIO\""
	@$(ECHO_MSG) "and/or \"-DWITHOUT_JOYSTICK\""

do-install:
	@(cd ${WRKSRC}/source && for f in ${PROGRAMS}; do \
		${INSTALL_PROGRAM} $$f ${PREFIX}/bin; done)
	@(cd ${WRKSRC}/man6 && for f in *.6; do \
		${INSTALL_MAN} $$f ${PREFIX}/man/man6; done)
	@${MKDIR} ${PREFIX}/share/imaze/labs
	@(cd ${WRKSRC}/labs && for f in *.lab; do \
		${INSTALL_DATA} $$f ${PREFIX}/share/imaze/labs; done)
	@${MKDIR} ${SOUNDDIR}
	@(cd ${WRKSRC}/sounds && for f in *.au; do \
		${INSTALL_DATA} $$f ${SOUNDDIR}; done)
	@(cd ${WRKSRC} && ${INSTALL_DATA} README ${PREFIX}/share/imaze)
	@$(ECHO_MSG) "Please read the file \"${PREFIX}/share/imaze/README\"."

.include <bsd.port.mk>
