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

MAKE_ARGS=	PG_CONFIG=${LOCALBASE}/bin/pg_config USE_PGXS=1 \
		docdir=${DOCSDIR} \
		install_bin=/usr/bin/install
TEST_TARGET=	installcheck
USE_LDCONFIG=	yes
USES=		gmake pgsql

DATADIR=	${PREFIX}/share/postgresql
DOCSDIR?=	${PREFIX}/share/doc/postgresql
PLIST_FILES=	lib/postgresql/pg_sphere.so \
		%%DATADIR%%/contrib/pg_sphere.sql

DOCS_MAKE_ARGS_OFF=	DOCS=""
DOCS_PLIST_FILES=	%%DOCSDIR%%/contrib/README.pg_sphere \
			%%DOCSDIR%%/contrib/COPYRIGHT.pg_sphere

post-patch:
	@${REINPLACE_CMD} -e 's|int4|int32|g' ${WRKSRC}/line.c ${WRKSRC}/line.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_sphere.so

.include <bsd.port.mk>
