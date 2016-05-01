# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	analogger
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast, flexible, easy to use logging service for Ruby

LICENSE=	RUBY

RUN_DEPENDS=	rubygem-eventmachine>=0.0.0:devel/rubygem-eventmachine

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	bin/analogger
ruby_OLD_CMD=	ruby

PLIST_FILES=	bin/analogger

.include <bsd.port.mk>
