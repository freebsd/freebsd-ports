# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	fgkicker
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.larfeliz.be/projects/files/fgkicker/
EXTRACT_SUFX=	.tgz

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Launcher frontend for FlightGear

RUN_DEPENDS=	fgfs:${PORTSDIR}/games/flightgear

USE_GNOME=	gtk20
USES=		gmake pkgconfig

NO_STAGE=	yes
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
