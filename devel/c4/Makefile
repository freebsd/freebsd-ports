# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	c4
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES+=	devel
MASTER_SITES=	http://public.perforce.com/public/perforce/utils/c4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CVS-like Frontend to Perforce

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	c4

MAN1=		c4.1

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c4 ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/c4.1 ${MAN1PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/c4.pdf ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/c4.ps ${DOCSDIR}/
.endif

.include <bsd.port.mk>
