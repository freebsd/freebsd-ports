# New ports collection makefile for:	aolserver-nspostgres
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nspostgres
PORTVERSION=	4.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	aolserver
PKGNAMEPREFIX=	aolserver-
DIST_SUBDIR=	aolserver

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Internal PostgreSQL driver for AOLserver

WRKSRC=		${WRKDIR}/nspostgres-${PORTVERSION}

AOLSERVERBASE?=	${PREFIX}/aolserver
BUILD_DEPENDS+=	${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${BUILD_DEPENDS}
PLIST_SUB+=	AOLSERVERBASE=${AOLSERVERBASE:S/${PREFIX}\///}

USE_PGSQL=	yes
DEFAULT_PGSQL_VER=	82
USE_GMAKE=	yes

MAKE_ARGS=	AOLSERVER=${AOLSERVERBASE} POSTGRES=${LOCALBASE} ACS=1

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
