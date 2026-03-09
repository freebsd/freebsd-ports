PORTNAME=	r18n-rails
PORTVERSION=	6.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Out-of-box R18n support for Ruby on Rails
WWW=		https://github.com/r18n/r18n-rails

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-net-smtp>=0.5.1<0.6:mail/rubygem-net-smtp \
		rubygem-r18n-rails-api>=6.0<7:devel/rubygem-r18n-rails-api \
		rubygem-rails81>=6.1<9:www/rubygem-rails81

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
