# Created by: Alexander Logvinov <ports@logvinov,com>
# $FreeBSD$

PORTNAME=	activerecord-jdbcmysql-adapter
PORTVERSION=	1.3.10
CATEGORIES=	databases rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ActiveRecord driver for MySQL using JDBC running under JRuby

RUN_DEPENDS=	rubygem-jdbc-mysql>=5.1.22:${PORTSDIR}/databases/rubygem-jdbc-mysql \
		rubygem-activerecord-jdbc-adapter>=1.3.10:${PORTSDIR}/databases/rubygem-activerecord-jdbc-adapter \
		jruby:${PORTSDIR}/lang/jruby

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
