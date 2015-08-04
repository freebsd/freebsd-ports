# Created by: Torsten Zühlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	4.1.12
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel41>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel41 \
		rubygem-activesupport41>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-arel>=5.0.0:${PORTSDIR}/databases/rubygem-arel

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	limit:^4\.1

.include <bsd.port.mk>
