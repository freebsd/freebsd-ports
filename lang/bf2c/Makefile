# New ports collection makefile for:    bf2c
# Date created:        4 Sep 2003
# Whom:                r.c.ladan@student.tue.nl
#
# $FreeBSD$
#

PORTNAME=	bf2c
PORTVERSION=    1.2.2
PORTREVISION=	1
CATEGORIES=     lang
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=bf2c

MAINTAINER=     r.c.ladan@student.tue.nl
COMMENT=        Optimizing BrainF*ck to C compiler

USE_GMAKE=      yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bf2c ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
