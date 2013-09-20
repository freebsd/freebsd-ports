# Created by: ijliao
# $FreeBSD$

PORTNAME=	cvsps
DISTVERSION=	2.2b1
CATEGORIES=	devel
MASTER_SITES=	http://www.cobite.com/cvsps/
PKGNAMESUFFIX?=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create patchset information from CVS

USE_GMAKE=	yes
ALL_TARGET=	cvsps

CONFLICTS=	cvsps-[12].[01]*

MAN1=		cvsps.1
PLIST_FILES=	bin/cvsps

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsps ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cvsps.1 ${MANPREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
