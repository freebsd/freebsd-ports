# New ports collection makefile for:	ruby-eet
# Date created:				06 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$

PORTNAME=	eet
PORTVERSION=	0.1.3
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.code-monkey.de/pub/ruby-eet/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-eet-${PORTVERSION}

MAINTAINER=	alex@foxybanana.com
COMMENT=	Ruby support for reading and writing EET files

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake
LIB_DEPENDS=	eet.9:${PORTSDIR}/devel/eet

USE_RUBY=	yes

.include <bsd.port.pre.mk>

do-build:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/rake PREFIX=${PREFIX}/

do-install:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/rake PREFIX=${PREFIX}/ install

.include <bsd.port.post.mk>
