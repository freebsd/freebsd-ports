# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcd
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	audio tk
MASTER_SITES=	LOCAL/jmz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl/Tk CD player

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_TK_WRAPPER=	yes
NO_STAGE=	yes

MAN1=		xcd.1

.if !defined(WITH_CDROM_PLAYER)
WITH_CDROM_PLAYER=	cd0
.endif

pre-extract:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You can define WITH_CDROM_PLAYER to set the default CD/DVD player"
	@${ECHO_CMD} "Default: cd0"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Use the CDPLAYER environment variable to override it."
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} 's|cd0c|${WITH_CDROM_PLAYER}|' ${WRKSRC}/cdplayer.cc
	@(cd ${WRKSRC} && ${SED} -e \
		's|/usr/local/bin/wish8.0|${WISH}| ; \
		 s|CDPLAYER|${PREFIX}/lib/xcd/cdplayer| ; \
		 s|BITMAPDIR|${PREFIX}/lib/xcd|' \
		< xcd.in > xcd)

do-build:
	(cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o cdplayer cdplayer.cc)

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} xcd ${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} xcd.1 ${MANPREFIX}/man/man1)
	@${MKDIR} ${PREFIX}/lib/xcd
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} cdplayer ${PREFIX}/lib/xcd)
	(cd ${WRKSRC}/bitmaps && ${INSTALL_DATA} *.xbm ${PREFIX}/lib/xcd)

.include <bsd.port.mk>
