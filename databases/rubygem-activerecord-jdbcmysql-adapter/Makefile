# Created by: Alexander Logvinov <ports@logvinov,com>
# $FreeBSD$

PORTNAME=	activerecord-jdbcmysql-adapter
PORTVERSION=	1.3.17
CATEGORIES=	databases rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ActiveRecord driver for MySQL using JDBC running under JRuby

LICENSE=	MIT

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby \
		rubygem-activerecord-jdbc-adapter>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activerecord-jdbc-adapter \
		rubygem-jdbc-mysql>=5.1.22:${PORTSDIR}/databases/rubygem-jdbc-mysql

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
