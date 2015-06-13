# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	2.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel4>=4.0:${PORTSDIR}/databases/rubygem-activemodel4 \
		rubygem-binding_of_caller>=0.7.2:${PORTSDIR}/devel/rubygem-binding_of_caller \
		rubygem-railties4>=4.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-sprockets-rails>=2.0:${PORTSDIR}/devel/rubygem-sprockets-rails

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
