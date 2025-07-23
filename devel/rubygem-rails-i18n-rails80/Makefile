PORTNAME=	rails-i18n
PORTVERSION=	8.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Set of common locale data and translations for Rails
WWW=		https://github.com/svenfuchs/rails-i18n

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-i18n>=0.7,2<2,2:devel/rubygem-i18n \
		rubygem-railties80>=8.0.0<9:www/rubygem-railties80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
