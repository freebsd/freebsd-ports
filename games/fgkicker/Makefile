# New ports collection makefile for:	fgkicker
# Date created:		30 November 2003
# Whom:			Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	fgkicker
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://users.pandora.be/ceppe/projects/files/fgkicker/
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@smluc.org
COMMENT=	A launcher frontend for FlightGear

RUN_DEPENDS=	fgfs:${PORTSDIR}/games/flightgear

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} "s|-fmessage-length=0|| ; s|-O0|${CFLAGS}|" ${WRKSRC}/fgkicker.mak

do-build:
	(cd ${WRKSRC} && ${GMAKE} -f ${PORTNAME}.mak ${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/airports.dat ${DATADIR}

install-user:
	${INSTALL_DATA} ${DATADIR}/airports.dat $$HOME

.include <bsd.port.mk>
