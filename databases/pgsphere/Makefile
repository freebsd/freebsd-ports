# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	pgsphere
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	databases geography

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Spherical data types, functions, and operators for PostgreSQL

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT.pg_sphere

OPTIONS_DEFINE=	DOCS

USES=		gmake pgsql
LLD_UNSAFE=	yes
USE_LDCONFIG=	yes
MAKE_ARGS=	PG_CONFIG=${LOCALBASE}/bin/pg_config USE_PGXS=1 \
		docdir=${DOCSDIR} \
		install_bin=/usr/bin/install
TEST_TARGET=	installcheck

DATADIR=	${PREFIX}/share/postgresql
DOCSDIR?=	${PREFIX}/share/doc/postgresql

GH_TAGNAME=	f36ffd6
USE_GITHUB=	yes

DOCS_MAKE_ARGS_OFF=	DOCS=""

post-patch:
	@${REINPLACE_CMD} -e 's|int4|int32|g' ${WRKSRC}/line.c ${WRKSRC}/line.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_sphere.so

.include <bsd.port.mk>
