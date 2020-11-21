# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gitlab-pg_query
PORTVERSION=	1.3.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Parses SQL queries using a copy of the PostgreSQL server query parser

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libpg_query.a:databases/libpg_query

USES=		gem
USE_RUBY=	yes

#CONFIGURE_ARGS=	--with-pgsql-include-dir=`${PG_CONFIG} --includedir` \
#		--with-pgsql-lib-dir=`${PG_CONFIG} --libdir`
#PG_CONFIG=	${LOCALBASE}/bin/pg_config

.include <bsd.port.mk>
