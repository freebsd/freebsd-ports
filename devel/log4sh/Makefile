# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	log4sh
PORTVERSION=	1.4.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%201.4.X%20%28stable%29/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A common logging library for Bourne shell scripts

PLIST_FILES=	lib/log4sh
PORTDOCS=	log4sh.html

ALL_TARGET=	build

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/src/shell/log4sh ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/log4sh.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
