# New ports collection makefile for:	Ruby-Search-Namazu
# Date created:		13 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	search-namazu
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	ftp://ftp.tietew.jp/pub/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	nmz.6:${PORTSDIR}/japanese/namazu2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_RUBY_RDTOOL=	yes

INSTALL_TARGET=	site-install

post-build:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}; ${RUBY_RD2} search-namazu.en.rd > search-namazu.en.html
	cd ${WRKSRC}; ${RUBY_RD2} search-namazu.ja.rd > search-namazu.ja.html
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${INSTALL_DATA} ${WRKSRC}/search-namazu.en.* ${RUBY_DOCDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/search-namazu.ja.* ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endif

.include <bsd.port.mk>
