# $FreeBSD$

PORTNAME=	newrelic-grape
PORTVERSION=	2.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@michael-fausten.de
COMMENT=	Newrelic instrument for grape

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS?=	rubygem-grape>=0:${PORTSDIR}/devel/rubygem-grape \
		rubygem-newrelic_rpm>=0:${PORTSDIR}/devel/rubygem-newrelic_rpm

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
