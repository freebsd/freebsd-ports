# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptiger
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	astro tk
MASTER_SITES=	SF/tkgeomap/${PORTNAME}/${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Displays U.S. Census Bureau populated places on a map

LIB_DEPENDS=	libtkgeomap.so:${PORTSDIR}/astro/tkgeomap

USES+=		tk:run
NO_BUILD=	yes
NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} -Ee 's,\[pwd\],${DATADIR}/src,;s,(lines/|places/|src/),${DATADIR}/\1,g;s,wish,${WISH},' ${WRKSRC}/src/PTiger.tcl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/src/PTiger.tcl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL} -d ${DATADIR}
	@${CP} -Rf ${WRKSRC}/lines ${WRKSRC}/places ${WRKSRC}/src ${DATADIR}/

.include <bsd.port.mk>
