PORTNAME=	sprockets-rails
PORTVERSION=	3.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Sprockets Rails integration
WWW=		https://github.com/rails/sprockets-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack-gitlab>=5.2:www/rubygem-actionpack-gitlab \
		rubygem-activesupport-gitlab>=5.2:devel/rubygem-activesupport-gitlab \
		rubygem-sprockets>=3.0.0:devel/rubygem-sprockets

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
