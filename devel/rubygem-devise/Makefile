# Created by: rpsfa@rit.edu
# $FreeBSD$

PORTNAME=	devise
PORTVERSION=	2.2.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Flexible authentication solution for Rails with Warden

RUN_DEPENDS=	rubygem-bcrypt-ruby>=3.0:${PORTSDIR}/security/rubygem-bcrypt-ruby \
		rubygem-warden>=1.2.1:${PORTSDIR}/devel/rubygem-warden \
		rubygem-orm_adapter>=0.1:${PORTSDIR}/devel/rubygem-orm_adapter \
		rubygem-railties>=3.1:${PORTSDIR}/www/rubygem-railties

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
