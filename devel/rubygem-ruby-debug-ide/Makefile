# Ports collection makefile for:	rubygem-ruby-debug-ide
# Date created:				22 June 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	ruby-debug-ide
PORTVERSION=	0.4.11
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IDE interface for ruby-debug

RUN_DEPENDS=	rubygem-ruby-debug-base>=0.10.0:${PORTSDIR}/devel/rubygem-ruby-debug-base

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RAKE=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rdebug-ide

MANUAL_PACKAGE_BUILD=	keeps hanging on pointyhat

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64
.endif

.include <bsd.port.post.mk>
