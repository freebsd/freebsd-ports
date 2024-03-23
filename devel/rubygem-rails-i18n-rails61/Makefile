PORTNAME=	rails-i18n
PORTVERSION=	7.0.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Common locale data and translations for Rails i18n
WWW=		https://github.com/svenfuchs/rails-i18n

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-i18n>=0.7,2<2,2:devel/rubygem-i18n \
		rubygem-railties61>=6.0<8:www/rubygem-railties61

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
