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

DEFAULT_PGSQL_VER?=74

# can't include <bsd.port.pre.mk> in a slave port
# so set these instead:
LOCALBASE?=	${DESTDIR}/usr/local
SED?=		/usr/bin/sed

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

DISTFILES=	postgresql-docs-${PORTVERSION}${EXTRACT_SUFX}
NO_BUILD=	YES
SLAVE_ONLY=	YES
PATCHDIR=	mustnotexist

do-install:
	@ $(MKDIR) ${DOCSDIR}/html; \
	${GZIP_CMD} -dc ${WRKSRC}/doc/postgres.tar.gz | \
	( cd ${DOCSDIR}/html && $(TAR) xf - )

post-install:
	@ ${TAR} ztf ${WRKSRC}/doc/postgres.tar.gz | ${GREP} -v /$$ | \
	  ${SED} "s,^,${DOCSDIR:S,^${PREFIX}/,,}/html/," >> ${TMPPLIST} ;\
	  ${TAR} ztf ${WRKSRC}/doc/postgres.tar.gz | ${GREP} /$$ | \
	  ${SED} "s,^,@dirrm\ ," >> ${TMPPLIST} ;\
	  ${ECHO} @dirrm ${DOCSDIR:S,^${PREFIX}/,,}/html >> ${TMPPLIST} ;\
	  ${ECHO} "@unexec rmdir %D/${DOCSDIR:S,^${PREFIX}/,,} 2> /dev/null || true" >> ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
