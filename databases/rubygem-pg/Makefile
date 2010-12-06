# New ports collection makefile for: pg
# Date created: 28 Jan 2009
# Whom: Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		pg
PORTVERSION=		0.10.0
CATEGORIES=		databases rubygems
MASTER_SITES=		RG

MAINTAINER=		ruby@FreeBSD.org
COMMENT=		Ruby interface to PostgreSQL library

USE_PGSQL=		yes
USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes

PG_CONFIG=		${LOCALBASE}/bin/pg_config
CONFIGURE_ARGS=		--with-pgsql-include-dir=`${PG_CONFIG} --includedir` \
			--with-pgsql-lib-dir=`${PG_CONFIG} --libdir`

.include <bsd.port.mk>
