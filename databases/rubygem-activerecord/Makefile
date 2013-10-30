# Created by: Jonathan Weiss (<jw@innerewut.de>)
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	3.2.15
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activemodel>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel \
		rubygem-tzinfo>=0.3.29:${PORTSDIR}/devel/rubygem-tzinfo \
		rubygem-arel>=3.0.2:${PORTSDIR}/databases/rubygem-arel

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE3
MYSQL_DESC=	Use native MySQL bindings
PGSQL_DESC=	Use native PostgreSQL bindings
SQLITE3_DESC=	Use native SQLite3 bindings
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

GEM_ENV+=	LANG=en_US.UTF-8

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${RUBY_PKGNAMEPREFIX}mysql>0:${PORTSDIR}/databases/ruby-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
.endif

.if ${PORT_OPTIONS:MSQLITE3}
RUN_DEPENDS+=	rubygem-sqlite3>=1.2.1:${PORTSDIR}/databases/rubygem-sqlite3
.endif

.include <bsd.port.mk>
