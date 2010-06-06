# Ports collection makefile for:	gem-activerecord
# Date created:				27 May 2005
# Whom:					Jonathan Weiss (<jw@innerewut.de>)
#
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	2.3.8
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

RUN_DEPENDS=	rubygem-activesupport>=2.3.4:${PORTSDIR}/devel/rubygem-activesupport

OPTIONS=	NATIVE_MYSQL "Use native MySQL bindings" Off\
		NATIVE_POSTGRESQL "Use native PostgreSQL bindings" Off\
		NATIVE_SQLITE3 "Use native SQLite3 bindings" Off
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

# to get RUBY_SITEARCHLIBDIR
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_NATIVE_MYSQL)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/mysql.so:${PORTSDIR}/databases/ruby-mysql
.endif

.if defined(WITH_NATIVE_POSTGRESQL)
RUN_DEPENDS+=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg
.endif

.if defined(WITH_NATIVE_SQLITE3)
RUN_DEPENDS+=	rubygem-sqlite3>=1.2.1:${PORTSDIR}/databases/rubygem-sqlite3
.endif

.include <bsd.port.post.mk>
