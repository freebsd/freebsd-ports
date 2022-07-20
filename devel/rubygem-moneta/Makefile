PORTNAME=	moneta
PORTVERSION=	1.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Unified interface to key/value stores

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	script/start-couchdb \
		script/start-services

.include <bsd.port.mk>
