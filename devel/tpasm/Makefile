# New ports collection makefile for:	tpasm
# Date created:				13 Feb 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	tpasm
PORTVERSION=	1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-assembler for variety of microprocessors and controllers

LICENSE=	GPLv2

USE_GMAKE=	yes
PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libdata/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/libdata/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CONVERSION_C166.TXT ${WRKSRC}/MANUAL.TXT \
		${WRKSRC}/README*.TXT ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
