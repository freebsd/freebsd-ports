# New ports collection makefile for:	hamsterdb
# Date created:				17 July 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hamsterdb
PORTVERSION=	1.0.9
CATEGORIES=	databases
MASTER_SITES=	http://hamsterdb.com/public/dl/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Lightweight Embedded Database Engine

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/Doxyfile ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/tutorial.odt ${DOCSDIR}
.endif

.include <bsd.port.mk>
