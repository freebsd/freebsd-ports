# New ports collection makefile for:	fbbi
# Date created:        22 December 2001
# Whom:                Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	fbbi
PORTVERSION=	0.98
CATEGORIES=	lang
MASTER_SITES=	http://www.catseye.mb.ca/esoteric/befunge/98/fbbi/
DISTNAME=	fbbiv098
EXTRACT_SUFX=	.zip

MAINTAINER=	llwang@infor.org

USE_ZIP=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}/src

pre-build:
	@${CP} ${WRKDIR}/fbbi.c ${WRKSRC}
	${REINPLACE_CMD} -e 's,#include <values.h>,,' ${WRKSRC}/bf98spc.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/fbbi ${LOCALBASE}/bin

.include <bsd.port.mk>
