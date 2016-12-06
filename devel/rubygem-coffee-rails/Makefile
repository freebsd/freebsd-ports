# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	coffee-rails
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Coffee Script adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-coffee-script>=2.2.0:devel/rubygem-coffee-script \
		rubygem-railties>=3.2.10:www/rubygem-railties

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PORTSCOUT=	limit:^3\.


DEPRECATED=	Depends on deprecated www/rubygem-railties
EXPIRATION_DATE=	2017-01-07

.include <bsd.port.mk>
