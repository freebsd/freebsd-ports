# New ports collection makefile for:	PostgreSQL docs
# Date created:		August 26, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PKGNAMESUFFIX=	-docs

MAINTAINER=	girgen@pingpong.net

POSTGRESQL_SUBPORT=	YES
POSTGRESQL_PORT?=	databases/postgresql7
.include <${.CURDIR}/../../${POSTGRESQL_PORT}/Makefile>
DISTFILES=	postgresql-docs-${PORTVERSION}${EXTRACT_SUFX}
.undef GNU_CONFIGURE
NO_BUILD=	YES

do-install:
	$(MKDIR) ${PREFIX}/share/doc/postgresql/html; \
	${GZIP_CMD} -dc ${WRKSRC}/doc/postgres.tar.gz | \
	( cd $(PREFIX)/share/doc/postgresql/html && $(TAR) xf - )

.include <bsd.port.mk>
