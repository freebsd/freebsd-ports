# New ports collection makefile for:    tavrasm
# Date created:                         12 December 2003
# Whom:                                 Wes Peters <wes@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	avra
PORTVERSION=	1.0.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	wes@FreeBSD.org
COMMENT=	Macro Assembler for Atmel AVR microcontrollers

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}
BUILD_WRKSRC=	${WRKSRC}/SOURCE
INSTALL_WRKSRC=	${WRKSRC}/SOURCE

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
