# New ports collection makefile for:	PostgreSQL docs
# Date created:		August 26, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTREVISION=	0
PKGNAMESUFFIX=	-docs

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	The PostgreSQL documentation set

POSTGRESQL_SUBPORT=	YES
POSTGRESQL_PORT?=	databases/postgresql7
.include <${.CURDIR}/../../${POSTGRESQL_PORT}/Makefile>
DISTFILES=	postgresql-docs-${PORTVERSION}${EXTRACT_SUFX}
.undef USE_GMAKE
.undef GNU_CONFIGURE
NO_BUILD=	YES

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

.include <bsd.port.mk>
