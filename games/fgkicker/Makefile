# New ports collection makefile for:	fgkicker
# Date created:		30 November 2003
# Whom:			Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	fgkicker
PORTVERSION=	0.4
CATEGORIES=	games
MASTER_SITES=	http://users.pandora.be/ceppe/linux/
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org
COMMENT=	A launcher frontend for FlightGear

RUN_DEPENDS=	fgfs:${PORTSDIR}/games/flightgear

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} "s|/usr/games/fgfs\",15|${PREFIX}/bin/fgfs\",511|" ${WRKSRC}/fgkicker.c
	@${REINPLACE_CMD} "s|-fmessage-length=0|| ; s|-O0|${CFLAGS}|" ${WRKSRC}/fgkicker.mak

do-build:
	(cd ${WRKSRC} && ${GMAKE} -f ${PORTNAME}.mak ${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
