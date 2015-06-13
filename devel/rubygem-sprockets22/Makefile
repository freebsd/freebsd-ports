# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	sprockets
PORTVERSION=	2.2.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	22

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files

LICENSE=	MIT

RUN_DEPENDS=	rubygem-hike>=1.2:${PORTSDIR}/devel/rubygem-hike \
		rubygem-multi_json>=1.9.2:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rack>=1.0:${PORTSDIR}/www/rubygem-rack \
		rubygem-tilt1>=1.1:${PORTSDIR}/devel/rubygem-tilt1

CONFLICTS_INSTALL=	rubygem-sprockets211-[0-9]*

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PORTSCOUT=	limit:^2\.2

.include <bsd.port.mk>
