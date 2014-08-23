# Created by: Alexander Logvinov <ports@logvinov,com>
# $FreeBSD$

PORTNAME=	activerecord-jdbc-adapter
PORTVERSION=	1.3.9
CATEGORIES=	databases rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	JDBC adapter for ActiveRecord, for use within JRuby on Rails

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby \
		rubygem-activerecord>=2.2:${PORTSDIR}/databases/rubygem-activerecord

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
