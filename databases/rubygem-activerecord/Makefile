# Ports collection makefile for:	gem-activerecord
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	3.0.5
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

RUN_DEPENDS=	rubygem-activesupport>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport \
  rubygem-activemodel>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel \
  rubygem-tzinfo>=0.3.23:${PORTSDIR}/devel/rubygem-tzinfo \
  rubygem-arel>=2.0.2:${PORTSDIR}/databases/rubygem-arel

USE_RUBY=   yes
USE_RUBYGEMS=   yes
RUBYGEM_AUTOPLIST=  yes

OPTIONS= \
	NATIVE_MYSQL 		"Use native MySQL bindings" 		Off \
	NATIVE_POSTGRESQL 	"Use native PostgreSQL bindings" 	Off \
	NATIVE_SQLITE3 		"Use native SQLite3 bindings" 		Off
OPTIONSFILE=   ${PORT_DBDIR}/rubygem-${PORTNAME}/options

.include <bsd.port.options.mk>

.if defined(WITH_NATIVE_MYSQL)
RUN_DEPENDS+=	${RUBY_PKGNAMEPREFIX}mysql>0:${PORTSDIR}/databases/ruby-mysql
.endif

.if defined(WITH_NATIVE_POSTGRESQL)
RUN_DEPENDS+=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
.endif

.if defined(WITH_NATIVE_SQLITE3)
RUN_DEPENDS+=	rubygem-sqlite3>=1.2.1:${PORTSDIR}/databases/rubygem-sqlite3
.endif

.include <bsd.port.mk>
