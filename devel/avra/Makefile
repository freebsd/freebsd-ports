# New ports collection makefile for:    tavrasm
# Date created:                         12 December 2003
# Whom:                                 Wes Peters <wes@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avra
PORTVERSION=	1.2.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	wes@FreeBSD.org
COMMENT=	Macro Assembler for Atmel AVR microcontrollers

WRKSRC=		${WRKDIR}
USE_AUTOTOOLS=	aclocal:110 autoconf:262 automake:110
AUTOMAKE_ARGS=	-a

PORTDOCS=	README

# Install the Avra README file as docs

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
