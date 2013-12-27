# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	pgsphere
PORTVERSION=	1.1.1
PORTREVISION=	3
CATEGORIES=	databases geography
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2558/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Spherical data types, functions, and operators for PostgreSQL

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS

MAKE_ARGS=	PG_CONFIG=${LOCALBASE}/bin/pg_config USE_PGXS=1 docdir=${DOCSDIR}
USE_LDCONFIG=	yes
USE_PGSQL=	yes
USES=		gmake

DATADIR=	${PREFIX}/share/postgresql
DOCSDIR?=	${PREFIX}/share/doc/postgresql
PLIST_FILES=	lib/postgresql/pg_sphere.so \
		%%DATADIR%%/contrib/pg_sphere.sql
PLIST_DIRSTRY=	%%DATADIR%%/contrib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	%%DOCSDIR%%/contrib/README.pg_sphere \
		%%DOCSDIR%%/contrib/COPYRIGHT.pg_sphere
PLIST_DIRS+=	%%DOCSDIR%%/contrib
.else
MAKE_ARGS+=	DOCS=""
.endif

regression-test test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} installcheck

.include <bsd.port.mk>
