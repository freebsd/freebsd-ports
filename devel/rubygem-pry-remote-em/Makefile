# Created by: Kimo <kimor79@yahoo.com>
# $FreeBSD$

PORTNAME=	pry-remote-em
PORTVERSION=	0.7.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Connect to Pry remotely using EventMachine

LICENSE=	MIT

RUN_DEPENDS=	rubygem-eventmachine>=0:devel/rubygem-eventmachine \
		rubygem-highline>=0:devel/rubygem-highline \
		rubygem-pry>=0.9<1:devel/rubygem-pry

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/pry-remote-em

.include <bsd.port.mk>
