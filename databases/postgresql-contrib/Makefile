# New ports collection makefile for:	postgresql-contrib
# Date created:		June 10, 2003
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTREVISION=	1
CATEGORIES=	databases
PKGNAMESUFFIX=	-contrib

MAINTAINER=	girgen@pingpong.net
COMMENT=	The contrib utilities from the PostgreSQL distribution

LIB_DEPENDS=	pq:${PORTSDIR}/${POSTGRESQL_PORT}

POSTGRESQL_PORT?=	databases/postgresql7
POSTGRESQL_SUBPORT=YES
.include <${.CURDIR}/../../${POSTGRESQL_PORT}/Makefile>

INSTALLS_SHLIB=	yes
USE_BISON=	yes

CONFIGURE_ARGS=	--with-libraries=${LOCALBASE}/lib \
		--with-includes=${LOCALBASE}/include \
		--docdir=${DOCSDIR}
MAKE_ARGS=	-C contrib

pre-build:
	cd ${WRKSRC}/src/backend ;\
	${GMAKE} ../../src/include/parser/parse.h ../../src/include/utils/fmgroids.h
	cd ${WRKSRC}/src/port; ${GMAKE}

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
