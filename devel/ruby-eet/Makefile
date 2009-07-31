# New ports collection makefile for:	ruby-eet
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	eet
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/ruby-eet/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-eet-${PORTVERSION}

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Ruby support for reading and writing EET files

LIB_DEPENDS=	eet.9:${PORTSDIR}/devel/eet

USE_RUBY=	yes
USE_RAKE=	yes

.include <bsd.port.pre.mk>

do-build:
	@cd ${WRKSRC} && ${RAKE_BIN} PREFIX=${PREFIX}/

do-install:
	@cd ${WRKSRC} && ${RAKE_BIN} PREFIX=${PREFIX}/ install

.include <bsd.port.post.mk>
