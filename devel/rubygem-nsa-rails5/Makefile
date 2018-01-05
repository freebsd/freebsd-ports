# $FreeBSD$

PORTNAME=	nsa
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Deliver Rails ActiveSupport::Notifications to a Statsd backend

RUN_DEPENDS=	rubygem-activesupport5>=4.2:devel/rubygem-activesupport5 \
		rubygem-concurrent-ruby>=1.0.0:devel/rubygem-concurrent-ruby \
		rubygem-sidekiq>=3.5.0:devel/rubygem-sidekiq \
		rubygem-statsd-ruby>=1.2:devel/rubygem-statsd-ruby

USES=		gem shebangfix
USE_RUBY=	yes

SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>
