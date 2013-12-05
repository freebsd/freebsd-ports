# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	3.2.16
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel \
		rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-arel>=3.0.2:${PORTSDIR}/databases/rubygem-arel \
		rubygem-tzinfo>=0.3.29:${PORTSDIR}/devel/rubygem-tzinfo

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3
MYSQL_DESC=	Use native MySQL bindings
PGSQL_DESC=	Use native PostgreSQL bindings
SQLITE3_DESC=	Use native SQLite3 bindings
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

GEM_ENV+=	LANG=en_US.UTF-8

MYSQL_RUN_DEPENDS=	${RUBY_PKGNAMEPREFIX}mysql>=0:${PORTSDIR}/databases/ruby-mysql
PGSQL_RUN_DEPENDS=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
SQLITE3_RUN_DEPENDS=	rubygem-sqlite3>=1.2.1:${PORTSDIR}/databases/rubygem-sqlite3

.include <bsd.port.mk>
