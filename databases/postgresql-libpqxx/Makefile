# New ports collection makefile for:	PostgreSQL Pgaccess
# Date created:		December 1st, 2002
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	libpqxx
PORTVERSION=	2.2.7
CATEGORIES=	databases
MASTER_SITES=	ftp://gborg.postgresql.org/pub/libpqxx/stable/
PKGNAMEPREFIX=	postgresql-
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	A new C++ interface for  PostgreSQL

LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_INC_LIBTOOL_VER=15
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
INSTALLS_SHLIB=	YES
PLIST_SUB=	PORTVERSION=${PORTVERSION}

CONFIGURE_ARGS=	--with-postgres=${LOCALBASE} \
		--enable-shared \
		--with-postgres-include=${LOCALBASE}/include/postgresql

POSTGRESQL_PORT?=	databases/postgresql7

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
BUILD_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
RUN_DEPENDS+=	${LOCALBASE}/lib/libstlport_gcc.so:${PORTSDIR}/devel/stlport
CXXFLAGS+=	-I${LOCALBASE}/include/stlport
LDFLAGS+=	-L${LOCALBASE}/lib -lstlport_gcc ${PTHREAD_LIBS}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
.endif

.include <bsd.port.post.mk>
