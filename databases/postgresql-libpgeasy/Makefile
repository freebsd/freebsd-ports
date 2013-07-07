# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PKGNAMEPREFIX=	postgresql-
PORTNAME=	libpgeasy
PORTVERSION=	3.0.4
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR=	projects/gborg/pgeasy/stable
DIST_SUBDIR=	postgresql

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	An easy-to-use C interface to PostgreSQL

USE_AUTOTOOLS=	libtool
USE_PGSQL=	YES
USES=		gmake
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
