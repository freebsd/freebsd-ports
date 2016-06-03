# Created by: Erik Greenwald <erik@smluc.org>
# $FreeBSD$

PORTNAME=	fgkicker
PORTVERSION=	1.0
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.larfeliz.be/projects/files/fgkicker/

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Launcher frontend for FlightGear

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	fgfs:games/flightgear

USE_GNOME=	gtk20
USES=		gmake pkgconfig tar:tgz

post-patch:
	@${REINPLACE_CMD} "s|-fmessage-length=0|| ; s|-O0|${CFLAGS}|" ${WRKSRC}/fgkicker.mak

do-build:
	(cd ${WRKSRC} && ${MAKE_CMD} -f ${PORTNAME}.mak ${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/airports.dat ${STAGEDIR}${DATADIR}

install-user:
	${INSTALL_DATA} ${DATADIR}/airports.dat $$HOME

.include <bsd.port.mk>
