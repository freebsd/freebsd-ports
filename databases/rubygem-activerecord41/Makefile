# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	activerecord
PORTVERSION=	4.1.14
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Object-relational mapping layer for Rails MVC Framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-activemodel41>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-activemodel41 \
		rubygem-activesupport41>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-arel5>=5.0.0:${PORTSDIR}/databases/rubygem-arel5

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	limit:^4\.1

.include <bsd.port.mk>
