# New ports collection makefile for:	redact
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	redact
PORTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	graphics ruby
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/redact/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	An edje compiler written in ruby

BUILD_DEPENDS=	${RUBY_SITEARCHLIBDIR}/imlib2.so:${PORTSDIR}/graphics/ruby-imlib2 \
		${RUBY_SITELIBDIR}/eet.rb:${PORTSDIR}/devel/ruby-eet
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RAKE=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${RAKE_BIN} PREFIX=${PREFIX}/ install

.include <bsd.port.post.mk>
