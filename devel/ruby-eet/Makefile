# New ports collection makefile for:	ruby-eet
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	eet
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/ruby-eet/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-eet-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby support for reading and writing EET files

DEPRECATED=	Doesn't work with Ruby 1.9
EXPIRATION_DATE=	2011-08-03

LIB_DEPENDS=	eet.5:${PORTSDIR}/devel/eet

USE_RUBY=	yes
USE_RAKE=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif

do-build:
	@cd ${WRKSRC} && ${RAKE_BIN} PREFIX=${PREFIX}/

do-install:
	@cd ${WRKSRC} && ${RAKE_BIN} PREFIX=${PREFIX}/ install

.include <bsd.port.post.mk>
