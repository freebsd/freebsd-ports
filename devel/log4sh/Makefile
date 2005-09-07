# New ports collection makefile for:	log4sh
# Date created:		2005-02-01
# Whom:			David Thiel <lx@redundancy.redundancy.org
#
# $FreeBSD$
#

PORTNAME=	log4sh
PORTVERSION=	1.2.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	A common logging library for Bourne shell scripts

PLIST_FILES=	lib/log4sh
PORTDOCS=	log4sh.html

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/log4sh ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/log4sh.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
