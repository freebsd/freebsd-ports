# New ports collection makefile for:	FreeRIDE-RRB
# Date created:		17 June 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	rrb
PORTVERSION=	0.0.3
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.kmc.gr.jp/proj/rrb/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Ruby Refactoring Browser for FreeRIDE and EMACS

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

do-install:
	@${ECHO_MSG} "===>  Running ${RUBY_SETUP} to install"
	@cd ${INSTALL_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} ${RUBY_FLAGS} ${RUBY_SETUP} install

.include <bsd.port.mk>
