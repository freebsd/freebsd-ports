# New ports collection makefile for:	PostgreSQL docs
# Date created:		August 26, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#
POSTGRESQL_PORT?=	databases/postgresql7

PORTNAME=	postgresql
PORTVERSION!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V PORTVERSION
PORTREVISION?=	0
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR!=	cd ${.CURDIR}/../../${POSTGRESQL_PORT} && ${MAKE} -V MASTER_SITE_SUBDIR
PKGNAMESUFFIX=	-docs
DISTFILES=	postgresql-docs-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	The PostgreSQL documentation set

MD5_FILE=	${.CURDIR}/../../${POSTGRESQL_PORT}/distinfo
NO_BUILD=	YES

do-install:
	@ $(MKDIR) ${DOCSDIR}/html; \
	${GZIP_CMD} -dc ${WRKSRC}/doc/postgres.tar.gz | \
	( cd $(DOCSDIR)/html && $(TAR) xf - )

post-install:
	@ ${TAR} ztf ${WRKSRC}/doc/postgres.tar.gz | ${GREP} -v /$$ | \
	  ${XARGS} printf "share/doc/postgresql/html/%s\n" >> ${TMPPLIST} ;\
	for dir in `$(TAR) ztf ${WRKSRC}/doc/postgres.tar.gz | ${GREP} /$$` ; do \
	  ${ECHO} @dirrm $$dir >> ${TMPPLIST} ;\
	done ;\
	${ECHO} @dirrm share/doc/postgresql/html >> ${TMPPLIST} ;\
	${ECHO} @dirrm share/doc/postgresql >> ${TMPPLIST} ;\
	${ECHO} '@unexec rmdir %D/share/postgresql 2> /dev/null || true' >> ${TMPPLIST}

.include <bsd.port.mk>
