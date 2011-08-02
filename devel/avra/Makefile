# New ports collection makefile for:    tavrasm
# Date created:                         12 December 2003
# Whom:                                 Wes Peters <@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avra
PORTVERSION=	1.2.1
PORTREVISION=	1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Macro Assembler for Atmel AVR microcontrollers

BROKEN=	does not fetch

WRKSRC=		${WRKDIR}
USE_AUTOTOOLS=	aclocal autoconf automake
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
