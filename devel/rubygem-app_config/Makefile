# $FreeBSD$

PORTNAME=	app_config
PORTVERSION=	2.1.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	milki@rescomp.berkeley.edu
COMMENT=	A ruby gem for storing application configuration

LICENSE=	MIT

OPTIONS_DEFINE=	MONGO SQLITE3
OPTIONS_DEFAULT=	SQLITE3

MONGO_DESC=	mongo backend support
SQLITE3_DESC=	sqlite3 backend support
OPTIONSFILE=	${PORT_DBDIR}/rubygem-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE3}
RUN_DEPENDS+=	rubygem-sqlite3>=0:${PORTSDIR}/databases/rubygem-sqlite3
.endif

.if ${PORT_OPTIONS:MMONGO}
RUN_DEPENDS+=	rubygem-mongo>=0:${PORTSDIR}/devel/rubygem-mongo
.endif

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
