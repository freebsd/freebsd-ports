# New ports collection makefile for:	jlint
# Date created:		June 2, 2001
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jlint
PORTVERSION=	3.0
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java program analyzer and checker

.if !defined(NOPORTDOCS)
PORTDOCS=	manual.pdf
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '1s,/bin/bash,/bin/sh,' ${WRKSRC}/jlint.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jlint ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/antic ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jlint.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
