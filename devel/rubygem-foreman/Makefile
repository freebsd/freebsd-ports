# $FreeBSD$

PORTNAME=	foreman
PORTVERSION=	0.78.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Process manager for applications with multiple components

LICENSE=	MIT

RUN_DEPENDS=	rubygem-thor>=0.19.1:devel/rubygem-thor

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	spec/resources/bin/env

PLIST_FILES=	bin/foreman

.include <bsd.port.mk>
