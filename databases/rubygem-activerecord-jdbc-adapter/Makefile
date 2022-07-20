PORTNAME=	activerecord-jdbc-adapter
PORTVERSION=	51.0
CATEGORIES=	databases rubygems java
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	JDBC adapter for ActiveRecord, for use within JRuby on Rails

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	jruby:lang/jruby \
		rubygem-activerecord5>=5.1.0:databases/rubygem-activerecord5

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
