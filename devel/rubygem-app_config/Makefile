# $FreeBSD$

PORTNAME=	app_config
PORTVERSION=	2.1.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	milki@FreeBSD.org
COMMENT=	Ruby gem for storing application configuration

LICENSE=	MIT

OPTIONS_DEFINE=	MONGO SQLITE3
OPTIONS_DEFAULT=	SQLITE3

MONGO_DESC=	mongo backend support
SQLITE3_DESC=	sqlite3 backend support

MONGO_RUN_DEPENDS=	rubygem-mongo>=0:${PORTSDIR}/devel/rubygem-mongo
SQLITE3_RUN_DEPENDS=	rubygem-sqlite3>=0:${PORTSDIR}/databases/rubygem-sqlite3

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
