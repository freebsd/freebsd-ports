# New ports collection makefile for:	jlint
# Date created:		June 2, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jlint
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	http://artho.com/jlint/

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Java program analyzer and checker

USE_REINPLACE=	YES

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' ${WRKSRC}/jlint.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jlint ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/antic ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jlint.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${WRKSRC}/manual.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
