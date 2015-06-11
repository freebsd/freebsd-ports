# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	2.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

RUN_DEPENDS=	rubygem-railties4>=4.0:${PORTSDIR}/www/rubygem-railties4 \
		rubygem-activemodel4>=4.0:${PORTSDIR}/databases/rubygem-activemodel4 \
		rubygem-sprockets-rails>=2.0:${PORTSDIR}/devel/rubygem-sprockets-rails \
		rubygem-binding_of_caller>=0.7.2:${PORTSDIR}/devel/rubygem-binding_of_caller

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

.include <bsd.port.mk>
