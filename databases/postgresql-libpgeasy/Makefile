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
COMMENT=	Easy-to-use C interface to PostgreSQL

OPTIONS_DEFINE=	DOCS EXAMPLES

USES+=		gmake libtool pgsql
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
DOCSDIR=	${PREFIX}/share/doc/postgresql/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/postgresql/${PORTNAME}
INSTALL_TARGET=	install-strip

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/libpgeasy.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
