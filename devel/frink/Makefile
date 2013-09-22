# Created by: Mikhail Teterin
# $FreeBSD$

PORTNAME=	frink
PORTVERSION=	2.2.2p4
CATEGORIES=	devel
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A tcl formatter and static tester

#MAN1=		${PORTNAME}.1
MANCOMPRESSED=	maybe
WRKSRC=		${WRKDIR}/${PORTNAME}-2.2.2

MAKEFILE=	${FILESDIR}/Makefile.bsd
NO_STAGE=	yes

.ifndef NOPORTDOCS
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
