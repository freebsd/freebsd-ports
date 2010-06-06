# Ports collection makefile for:	rubygem-activerecord-jdbcmysql-adapter
# Date created:				22 July 2008
# Whom:					Alexander Logvinov <ports@logvinov,com>
#
# $FreeBSD$

PORTNAME=	activerecord-jdbcmysql-adapter
PORTVERSION=	0.9.2
CATEGORIES=	databases rubygems java
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	jruby-extras

MAINTAINER=	avl@FreeBSD.org
COMMENT=	An ActiveRecord driver for MySQL using JDBC running under JRuby

RUN_DEPENDS=	rubygem-jdbc-mysql>=5.0.4:${PORTSDIR}/databases/rubygem-jdbc-mysql \
		rubygem-activerecord-jdbc-adapter>=0.8.2:${PORTSDIR}/databases/rubygem-activerecord-jdbc-adapter \
		jruby:${PORTSDIR}/lang/jruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
