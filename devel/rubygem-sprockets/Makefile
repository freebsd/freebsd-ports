# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	sprockets
PORTVERSION=	2.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files

LICENSE=	MIT

RUN_DEPENDS=	rubygem-tilt>=1.1:${PORTSDIR}/devel/rubygem-tilt \
		rubygem-hike>=1.2:${PORTSDIR}/devel/rubygem-hike \
		rubygem-multi_json>=1.5.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-rack>=1.0:${PORTSDIR}/www/rubygem-rack

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sprockets

.include <bsd.port.mk>
