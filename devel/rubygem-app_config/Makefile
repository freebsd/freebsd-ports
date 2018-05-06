# $FreeBSD$

PORTNAME=	app_config
PORTVERSION=	2.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby gem for storing application configuration

LICENSE=	MIT

OPTIONS_DEFINE=	MONGODB SQLITE3
OPTIONS_DEFAULT=SQLITE3
MONGODB_DESC=	MongoDB backend support
SQLITE3_DESC=	SQLite 3 backend support

MONGODB_RUN_DEPENDS=	rubygem-mongo>=0:devel/rubygem-mongo
SQLITE3_RUN_DEPENDS=	rubygem-sqlite3>=0:databases/rubygem-sqlite3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
