# Ports collection makefile for:	rubygem-ruby-debug-ide
# Date created:				22 June 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ruby-debug-ide
PORTVERSION=	0.4.10
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	debug-commons

MAINTAINER=	avl@FreeBSD.org
COMMENT=	IDE interface for ruby-debug

RUN_DEPENDS=	rubygem-ruby-debug-base>=0.10.0:${PORTSDIR}/devel/rubygem-ruby-debug-base

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rdebug-ide

.include <bsd.port.mk>
