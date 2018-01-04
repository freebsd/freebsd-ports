# $FreeBSD$

PORTNAME=	rails-i18n
PORTVERSION=	4.0.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-4

MAINTAINER=	idefix@fechner.net
COMMENT=	Common locale data and translations for Rails i18n

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-i18n>=0.7:devel/rubygem-i18n \
		rubygem-railties4>=4.0:www/rubygem-railties4

PORTSCOUT=	limit:^4\.

NO_ARCH=	yes

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
