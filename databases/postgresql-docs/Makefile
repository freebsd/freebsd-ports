# New ports collection makefile for:	PostgreSQL docs
# Date created:		August 26, 2002
# Whom:			Palle Girgensohn <girgen@partitur.se>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PKGNAMESUFFIX=	-docs

MAINTAINER=	girgen@partitur.se

POSTGRESQL_SUBPORT=	YES
.include <${.CURDIR}/../postgresql7/Makefile>
DISTFILES=	postgresql-docs-${PORTVERSION}${EXTRACT_SUFX}
.undef GNU_CONFIGURE
NO_BUILD=	YES

do-install:
	$(MKDIR) ${PREFIX}/share/doc/postgresql/html; \
	${GZIP_CMD} -dc ${WRKSRC}/doc/postgres.tar.gz | \
	( cd $(PREFIX)/share/doc/postgresql/html && $(TAR) xf - )

.include <bsd.port.mk>
