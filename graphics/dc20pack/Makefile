# Created by: Maurice Castro <maurice@serc.rmit.edu.au>
# $FreeBSD$

PORTNAME=	dc20pack
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/capture

MAINTAINER=	maurice@castro.aus.net
COMMENT=	Digital camera control and download tool for Kodak DC20/25 camera

USES=		tar:tgz

NO_WRKSUBDIR=	yes

post-extract:
	for file in `${FIND} ${WRKSRC} -type f`; do \
		${TR} -d '\015' < $${file} > $${file}.new; \
		${MV} $${file}.new $${file}; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dc20dump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dc20term ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dc2totga ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
