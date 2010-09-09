# New ports collection makefile for:	ruby-postgres
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	postgres
PORTVERSION=	0.7.9.2008.01.28
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ruby interface to PostgreSQL library

USE_PGSQL=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PG_CONFIG=	${LOCALBASE}/bin/pg_config
CONFIGURE_ARGS=	--with-pgsql-include-dir=`${PG_CONFIG} --includedir` \
		--with-pgsql-lib-dir=`${PG_CONFIG} --libdir`

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == "1.9"
BROKEN=		does not compile with ruby 1.9, please use rubygem-pg
.endif

.include <bsd.port.post.mk>
