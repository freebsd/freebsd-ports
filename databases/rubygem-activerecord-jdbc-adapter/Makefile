# Created by: Alexander Logvinov <ports@logvinov,com>
# $FreeBSD$

PORTNAME=	activerecord-jdbc-adapter
PORTVERSION=	1.3.17
CATEGORIES=	databases rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	JDBC adapter for ActiveRecord, for use within JRuby on Rails

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	jruby:${PORTSDIR}/lang/jruby \
		rubygem-activerecord4>=2.2:${PORTSDIR}/databases/rubygem-activerecord4

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
