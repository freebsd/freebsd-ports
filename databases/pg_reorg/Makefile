# New ports collection makefile for:	pg_reorg
# Date created:			January 15, 2011
# Whom:					alp@sfedu.ru
# $FreeBSD$

PORTNAME=	pg_reorg
PORTVERSION=	1.1.7
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3104/

MAINTAINER=	alp@sfedu.ru
COMMENT=	PostgreSQL utility to reorganize tables

LICENSE=	BSD

MAKE_ENV=	USE_PGXS=0
USE_GMAKE=	yes
USE_PGSQL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
.endif

.include <bsd.port.mk>
