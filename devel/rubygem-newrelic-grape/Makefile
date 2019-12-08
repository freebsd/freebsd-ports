# $FreeBSD$

PORTNAME=	newrelic-grape
PORTVERSION=	2.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Newrelic instrument for grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-grape>=0:devel/rubygem-grape \
		rubygem-newrelic_rpm>=0:devel/rubygem-newrelic_rpm

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
