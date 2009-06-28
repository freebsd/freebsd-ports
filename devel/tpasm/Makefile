# New ports collection makefile for:	tpasm
# Date created:				13 Feb 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	tpasm
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cross-assembler for 680x, 68HC11, 6502, Sunplus, 8051, Z80, PIC, AVR

USE_GMAKE=	yes
PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/libdata/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.inc \
		${PREFIX}/libdata/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL.TXT ${WRKSRC}/README*.TXT ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
