# Ports collection makefile for:	rubygem-app_config
# Date created:				2011-07-28
# Whom:					milki <milki@rescomp.berkeley.edu>
#
# $FreeBSD$

PORTNAME=	app_config
PORTVERSION=	0.7.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	A ruby gem for storing application configuration

LICENSE=	MIT

OPTIONS=	SQLITE3 "sqlite3 backend support" Off
#			MONGO "mongo backend support Off  # No port yet

.include <bsd.port.options.mk>

.if !defined(WITHOUT_SQLITE3)
RUN_DEPENDS+=	rubygem-sqlite-ruby>=0:${PORTSDIR}/databases/rubygem-sqlite3-ruby
.endif

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
