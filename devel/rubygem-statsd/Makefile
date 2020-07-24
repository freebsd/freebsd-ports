# Created by: Evan Sarmiento <bsdports@wayfair.com>
# $FreeBSD$

PORTNAME=	statsd
PORTVERSION=	0.5.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby port of the statsd python and node.js tools

RUN_DEPENDS=	rubygem-erubis>=2.6.6:www/rubygem-erubis \
		rubygem-eventmachine>=0.12.10:devel/rubygem-eventmachine \
		rubygem-mongo>=1.2.4:devel/rubygem-mongo

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/statsd

.include <bsd.port.mk>
