PORTNAME=	nsa
PORTVERSION=	0.2.8
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Deliver Rails ActiveSupport::Notifications to a Statsd backend
WWW=		https://github.com/localshred/nsa

RUN_DEPENDS=	rubygem-activesupport5>=4.2<7:devel/rubygem-activesupport5 \
		rubygem-concurrent-ruby>=1.0.2<2:devel/rubygem-concurrent-ruby \
		rubygem-sidekiq>=3.5:devel/rubygem-sidekiq \
		rubygem-statsd-ruby>=1.4.0<2:devel/rubygem-statsd-ruby

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>
