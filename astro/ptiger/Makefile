# New ports collection makefile for:	ptiger
# Date created:		26 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ptiger
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	astro tk
MASTER_SITES=	SF/tkgeomap/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Displays U.S. Census Burea populated places on a map

LIB_DEPENDS=	tkgeomap.0:${PORTSDIR}/astro/tkgeomap

USE_TK_RUN=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -Ee 's,\[pwd\],${DATADIR}/src,;s,(lines/|places/|src/),${DATADIR}/\1,g;s,wish,${WISH},' ${WRKSRC}/src/PTiger.tcl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/src/PTiger.tcl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL} -d ${DATADIR}
	@${CP} -Rf ${WRKSRC}/lines ${WRKSRC}/places ${WRKSRC}/src ${DATADIR}/

.include <bsd.port.mk>
