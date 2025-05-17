PORTNAME=	health_check
PORTVERSION=	3.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple health check of Rails app for uptime monitoring
WWW=		https://github.com/ianheggie/health_check

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties-gitlab>=5.0:www/rubygem-railties-gitlab

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	test/*railsapp

.include <bsd.port.mk>
