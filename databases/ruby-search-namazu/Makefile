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
COMMENT=	Ruby library which wraps libnmz of Namazu

LIB_DEPENDS=	nmz.6:${PORTSDIR}/japanese/namazu2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	search-namazu.en.rd search-namazu.ja.rd
DOCS_EN=	${RUBY_RD_FILES:M*.en.rd} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.ja.rd} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

BROKEN=		"Does not install (cannot open Makefile)"

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
