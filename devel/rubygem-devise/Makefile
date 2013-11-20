# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	devise
PORTVERSION=	3.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

LICENSE=	MIT

RUN_DEPENDS=	rubygem-bcrypt-ruby>=3.0:${PORTSDIR}/security/rubygem-bcrypt-ruby \
		rubygem-orm_adapter>=0.1:${PORTSDIR}/devel/rubygem-orm_adapter \
		rubygem-railties>=3.2.6:${PORTSDIR}/www/rubygem-railties \
		rubygem-thread_safe>=0.1:${PORTSDIR}/devel/rubygem-thread_safe \
		rubygem-warden>=1.2.3:${PORTSDIR}/devel/rubygem-warden

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
