# New ports collection makefile for:	dc20pack
# Date created:		Jul 31 1999
# Whom:			Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

PORTNAME=		dc20pack
PORTVERSION=		1.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/capture
EXTRACT_SUFX=		.tgz

MAINTAINER=		maurice@serc.rmit.edu.au

WRKSRC=			${WRKDIR}
USE_REINPLACE=		yes

post-extract:
	@ /usr/bin/find ${WRKSRC} -type f | xargs ${REINPLACE_CMD} -e 's/\r//g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dc20dump ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dc20term ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dc2totga ${PREFIX}/bin

.include <bsd.port.mk>
