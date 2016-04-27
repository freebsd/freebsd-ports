# Created by: Mikhail T. <m.tsatsenko@gmail.com>
# $FreeBSD$

PORTNAME=	sprockets
PORTVERSION=	2.11.3
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	211

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library that preprocesses and concatenates JavaScript files

LICENSE=	MIT

RUN_DEPENDS=	rubygem-hike>=1.2:devel/rubygem-hike \
		rubygem-multi_json>=1.0:devel/rubygem-multi_json \
		rubygem-rack16>=1.0:www/rubygem-rack16 \
		rubygem-tilt1>=1.1:devel/rubygem-tilt1

CONFLICTS_INSTALL=	rubygem-sprockets-[0-9]*

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/sprockets

PORTSCOUT=	limit:^2\.11

.include <bsd.port.mk>
