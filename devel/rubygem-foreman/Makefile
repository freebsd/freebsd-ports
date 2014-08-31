# $FreeBSD$

PORTNAME=	foreman
PORTVERSION=	0.75.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Process manager for applications with multiple components

RUN_DEPENDS=	rubygem-dotenv>=0.11.1:${PORTSDIR}/misc/rubygem-dotenv \
		rubygem-thor>=0.19.1:${PORTSDIR}/devel/rubygem-thor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/foreman

.include <bsd.port.mk>
