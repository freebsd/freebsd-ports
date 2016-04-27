# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	3.2.22.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel>=${PORTVERSION}:databases/rubygem-activemodel \
		rubygem-activesupport>=${PORTVERSION}:devel/rubygem-activesupport \
		rubygem-arel3>=3.0.3:databases/rubygem-arel3 \
		rubygem-tzinfo03>=0.3.29:devel/rubygem-tzinfo03

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3
MYSQL_DESC=	Use native MySQL bindings
PGSQL_DESC=	Use native PostgreSQL bindings
SQLITE3_DESC=	Use native SQLite3 bindings

GEM_ENV+=	LANG=en_US.UTF-8

MYSQL_RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}mysql>=0:databases/ruby-mysql
PGSQL_RUN_DEPENDS=	rubygem-pg>=0:databases/rubygem-pg
SQLITE3_RUN_DEPENDS=	rubygem-sqlite3>=1.2.1:databases/rubygem-sqlite3

.include <bsd.port.mk>
