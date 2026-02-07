PORTNAME=	rails-i18n
PORTVERSION=	7.0.10
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of common locale data and translations for Rails
WWW=		https://github.com/svenfuchs/rails-i18n

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-i18n>=0.7,2<2,2:devel/rubygem-i18n \
		rubygem-railties71>=6.0.0<8:www/rubygem-railties71

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.

.include <bsd.port.mk>
