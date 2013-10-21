# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ruby-debug-ide
PORTVERSION=	0.4.16
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IDE interface for ruby-debug

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-21

RUN_DEPENDS=	rubygem-ruby-debug-base>=0.10.0:${PORTSDIR}/devel/rubygem-ruby-debug-base

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes

RELATIVE_VER=	0.0.9
PLIST_SUB+=	RELATIVE_VER=${RELATIVE_VER}

NO_STAGE=	yes
.include <bsd.port.mk>
