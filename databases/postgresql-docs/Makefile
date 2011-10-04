# New ports collection makefile for:	PostgreSQL docs
# Date created:		August 26, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PORTREVISION=	0
PKGNAMESUFFIX=	-docs

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	The PostgreSQL documentation set

MASTERDIR=	${.CURDIR}/../postgresql${PGSQL_VER}-server

DEFAULT_PGSQL_VER?=84

# can't include <bsd.port.pre.mk> in a slave port
# so set these instead:
LOCALBASE?=	/usr/local
SED?=		/usr/bin/sed

CONFLICTS=	postgresql-docs

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\).*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

.if (${PGSQL_VER} == 90) || (${PGSQL_VER} == 91)
BROKEN=		"not implemented yet"
.endif
 
NO_BUILD=	YES
SLAVE_ONLY=	YES
PATCHDIR=	mustnotexist

PGDOCSDIR?=	${DOCSDIR}/release-${PGSQL_VER}

do-install:
	@ $(MKDIR) ${PGDOCSDIR}; \
	${GZIP_CMD} -dc ${WRKSRC}/doc/postgres.tar.gz | \
	( cd ${PGDOCSDIR} && $(TAR) xf - )

post-install:
	@ ${TAR} ztf ${WRKSRC}/doc/postgres.tar.gz | ${GREP} -v /$$ | \
	  ${SED} "s,^,${PGDOCSDIR:S,^${PREFIX}/,,}/," >> ${TMPPLIST} ;\
	  ${TAR} ztf ${WRKSRC}/doc/postgres.tar.gz | ${GREP} /$$ | \
	  ${SED} "s,^,@dirrm\ ," >> ${TMPPLIST} ;\
	  ${ECHO} @dirrm ${PGDOCSDIR:S,^${PREFIX}/,,} >> ${TMPPLIST} ;\
	  ${ECHO} "@unexec rmdir %D/${DOCSDIR:S,^${PREFIX}/,,} 2> /dev/null || true" >> ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
