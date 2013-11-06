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

BROKEN=		Does not build

USES+=		tk
NO_STAGE=	yes

MAN1=		xcd.1

WITH_CDROM_PLAYER?=	cd0

MAKE_ENV+=	BINDIR="${PREFIX}/bin" \
		CDDIR="${PREFIX}/lib/xcd" \
		BITMAPDIR="${PREFIX}/lib/xcd" \
		MANDIR="${MANPREFIX}/man/man1"

pre-extract:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You can define WITH_CDROM_PLAYER to set the default CD/DVD player"
	@${ECHO_CMD} "Default: cd0"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Use the CDPLAYER environment variable to override it."
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e 's|cd0c|${WITH_CDROM_PLAYER}|' ${WRKSRC}/cdplayer.cc
	@${REINPLACE_CMD} -e 's|/usr/local/bin/wish8.0|${WISH}|' ${WRKSRC}/xcd.in

.include <bsd.port.mk>
