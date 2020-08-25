# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	health_check
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple health check of Rails app for uptime monitoring

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-railties60>=5.0:www/rubygem-railties60

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	test/*railsapp

NO_ARCH=	yes

.include <bsd.port.mk>
