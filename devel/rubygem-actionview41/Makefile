# Created by: Torsten Zühlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	actionview
PORTVERSION=	4.1.12
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)

RUN_DEPENDS=	rubygem-activesupport41>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-builder32>=3.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

PORTSCOUT=	limit:^4\.1

.include <bsd.port.mk>
