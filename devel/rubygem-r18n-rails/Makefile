PORTNAME=	r18n-rails
PORTVERSION=	5.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Out-of-box R18n support for Ruby on Rails

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-r18n-rails-api>=5.0<6:devel/rubygem-r18n-rails-api \
		rubygem-rails60>=5.0<7:www/rubygem-rails60

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
