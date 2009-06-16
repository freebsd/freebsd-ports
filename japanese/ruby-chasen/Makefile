# New ports collection makefile for:	Ruby-ChaSen
# Date created:		1 Mar 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	chasen
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	http://www.itlb.te.noda.tus.ac.jp/~ikarashi/ruby/
DISTNAME=	${PORTNAME}${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ChaSen module for Ruby

LIB_DEPENDS=	chasen.2:${PORTSDIR}/japanese/chasen-base

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-chasen-include="${PREFIX}/include/chasen" \
		--with-chasen-lib="${PREFIX}/lib"
INSTALL_TARGET=	site-install

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja/
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/ja/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/chasen.html ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.post.mk>
