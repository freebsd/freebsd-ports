# New ports collection makefile for:	xeartk
# Date created:		26 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xeartk
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	astro tk
MASTER_SITES=	SF/tkgeomap/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small demo for tkgeomap

LIB_DEPENDS=	tkgeomap.0:${PORTSDIR}/astro/tkgeomap

USE_TK_RUN=	yes
NO_BUILD=	yes
DATA_FILES=	README cities land.xdr rivers.xdr water.xdr
PLIST_FILES=	bin/${PORTNAME} ${DATA_FILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's,data/,${DATADIR}/,g;s,wish,${WISH},' ${WRKSRC}/src/XEartk.tcl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/src/XEartk.tcl ${PREFIX}/bin/${PORTNAME}
	@${INSTALL} -d ${DATADIR}
	@${INSTALL_DATA} ${DATA_FILES:S,^,${WRKSRC}/data/,} ${DATADIR}/

.include <bsd.port.mk>
