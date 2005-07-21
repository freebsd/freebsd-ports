# New ports collection makefile for:	columns
# Date created:				26 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	columns
PORTVERSION=	1.2b
PORTREVISION=	1
CATEGORIES=	games
# mastersite disappeared in December 2000
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry
DISTNAME=	Columns-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice little implementation of columns game for X Window System

USE_SDL=	sdl
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/Columns
PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
