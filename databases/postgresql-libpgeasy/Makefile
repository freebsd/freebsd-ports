# New ports collection makefile for:	PostgreSQL library pgeasy
# Date created:		October 24st, 2004
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PKGNAMEPREFIX=	postgresql-
PORTNAME=	libpgeasy
PORTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	projects/gborg/pgeasy/stable
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	An easy-to-use C interface to PostgreSQL

USE_AUTOTOOLS=	libtool:22
USE_PGSQL=	YES
USE_GMAKE=	YES
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
DOCSDIR=	${PREFIX}/share/doc/postgresql/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/postgresql/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	@- ${MKDIR} -m 755 ${EXAMPLESDIR} ;\
	${INSTALL} ${WRKSRC}/examples/* ${EXAMPLESDIR} ;\
	${MKDIR} -m 755 ${DOCSDIR} ;\
	${INSTALL} ${WRKSRC}/docs/libpgeasy.html ${DOCSDIR}
.endif

.include <bsd.port.mk>

