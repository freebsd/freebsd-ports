# New ports collection makefile for:	postgresql-contrib
# Date created:		June 10, 2003
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#
POSTGRESQL_PORT?=	databases/postgresql7

PORTNAME=	postgresql
PORTVERSION!=	${MAKE} -C ${.CURDIR}/../../${POSTGRESQL_PORT} -V PORTVERSION
PORTREVISION?=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL}
MASTER_SITE_SUBDIR!=	${MAKE} -C ${.CURDIR}/../../${POSTGRESQL_PORT} -V MASTER_SITE_SUBDIR
PKGNAMESUFFIX=	-contrib
DISTFILES!=	${MAKE} -C ${.CURDIR}/../../${POSTGRESQL_PORT} -V DISTFILES
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	The contrib utilities from the PostgreSQL distribution

LIB_DEPENDS=	pq:${PORTSDIR}/${POSTGRESQL_PORT}

USE_BISON=	YES
INSTALLS_SHLIB=	yes
MD5_FILE=	${.CURDIR}/../../${POSTGRESQL_PORT}/distinfo

USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include \
		--docdir=${DOCSDIR}
MAKE_ARGS=	-C contrib

pre-build:
	cd ${WRKSRC}/src/backend ;\
	${GMAKE} ../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h

post-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/contrib/ipc_check/ipc_check.pl ${PREFIX}/bin/ipc_check ;\
	  ${INSTALL_DATA} ${WRKSRC}/contrib/ipc_check/README ${DOCSDIR}/contrib/README.ipc_check ;\
	  ${INSTALL_SCRIPT} ${WRKSRC}/contrib/reindexdb/reindexdb ${PREFIX}/bin/reindexdb ;\
	  ${INSTALL_DATA} ${WRKSRC}/contrib/reindexdb/README ${DOCSDIR}/contrib/README.reindexdb
	@ ${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/README
	@ ${ECHO} ==================================== ;\
	  ${SED} -e "s,/usr/local,${PREFIX},g"  ${PKGDIR}/pkg-message ;\
	  ${ECHO} ====================================

.include <bsd.port.mk>
