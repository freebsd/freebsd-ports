# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	devise
PORTVERSION=	3.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS_SINGLE=	RAILS
OPTIONS_SINGLE_RAILS=	RAILS RAILS4
OPTIONS_DEFAULT=	RAILS

RUN_DEPENDS=	rubygem-bcrypt-ruby>=3.0:${PORTSDIR}/security/rubygem-bcrypt-ruby \
		rubygem-orm_adapter>=0.1:${PORTSDIR}/devel/rubygem-orm_adapter \
		rubygem-thread_safe>=0.1:${PORTSDIR}/devel/rubygem-thread_safe \
		rubygem-warden>=1.2.3:${PORTSDIR}/devel/rubygem-warden

.include <bsd.port.options.mk>

RAILS_RUN_DEPENDS=	rubygem-railties>=3.2.6:${PORTSDIR}/www/rubygem-railties \
RAILS4_RUN_DEPENDS=	rubygem-railties4>=4.1.1:${PORTSDIR}/www/rubygem-railties4 \

.include <bsd.port.mk>
