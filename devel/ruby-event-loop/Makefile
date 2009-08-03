# New ports collection makefile for:	ruby-event-loop
# Date created:		08 November 2006
# Whom:			Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	event-loop
PORTVERSION=	0.3
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.brockman.se/software/ruby-event-loop/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An Event loop for Ruby

USE_RUBY=	yes
USE_RAKE=	yes

do-configure:
	@cd ${WRKSRC} && ${RUBY} setup.rb config --prefix=${PREFIX}

do-build:
	@cd ${WRKSRC} && ${RUBY} setup.rb setup

do-install:
	@cd ${WRKSRC} && ${RUBY} setup.rb install

.include <bsd.port.mk>
