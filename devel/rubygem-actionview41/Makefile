# Created by: Torsten Zuhlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	actionview
PORTVERSION=	4.1.14
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	41

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Rendering framework putting the V in MVC (part of Rails)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

DEPRECATED=	Rails 4.1 is no longer supported - please switch to Rails 4.2
EXPIRATION_DATE=	2016-03-31

RUN_DEPENDS=	rubygem-activesupport41>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-activesupport41 \
		rubygem-builder32>=3.2:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-erubis>=2.7.0:${PORTSDIR}/www/rubygem-erubis

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	limit:^4\.1

.include <bsd.port.mk>
