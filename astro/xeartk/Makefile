# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xeartk
PORTVERSION=	2.2
PORTREVISION=	3
CATEGORIES=	astro tk
MASTER_SITES=	SF/tkgeomap/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small demo for tkgeomap

LIB_DEPENDS=	libtkgeomap.so:astro/tkgeomap

USES=		tk:run
NO_BUILD=	yes
NO_ARCH=	yes
DATA_FILES=	README cities land.xdr rivers.xdr water.xdr
PLIST_FILES=	bin/${PORTNAME} \
		${DATA_FILES:S,^,%%DATADIR%%/,}

post-patch:
	@${REINPLACE_CMD} -e 's,data/,${DATADIR}/,g;s,wish,${WISH},' ${WRKSRC}/src/XEartk.tcl
	@${REINPLACE_CMD} -e 's| 0\([0-9]\)| \1|g' ${WRKSRC}/data/cities

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/XEartk.tcl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DATA_FILES:S,^,${WRKSRC}/data/,} ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
