# New ports collection makefile for:	tpasm
# Date created:				13 Feb 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	tpasm
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ct0.com/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	danfe@regency.nsu.ru
COMMENT=	Cross-assembler for 680x, 68hc11, 6502, Sunplus, 8051, Z80, PIC, AVR

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

	@${MKDIR} ${PREFIX}/libdata/${PORTNAME}
.for file in 8051 8052 80c390 avr p16c505 picmacros
	${INSTALL_DATA} ${WRKSRC}/include/${file}.inc ${PREFIX}/libdata/${PORTNAME}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/MANUAL.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
