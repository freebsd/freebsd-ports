PORTNAME=	rails-i18n
PORTVERSION=	6.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails613

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Common locale data and translations for Rails i18n

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

RUN_DEPENDS=	rubygem-i18n>=0.7,2<2,2:devel/rubygem-i18n \
		rubygem-railties613>=6.0<7:www/rubygem-railties613

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
