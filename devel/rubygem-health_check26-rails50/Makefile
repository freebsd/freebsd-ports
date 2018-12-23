# $FreeBSD$

PORTNAME=	health_check
PORTVERSION=	2.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	26-rails50

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple health check of Rails app for uptime monitoring

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-rails50>=4.0:www/rubygem-rails50

PORTSCOUT=	limit:^2\.6

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	test/*railsapp

NO_ARCH=	yes

.include <bsd.port.mk>
