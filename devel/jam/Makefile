# Created by: Jeffrey Hsu <hsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jam
PORTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/jam/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A build utility like make(1)

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
