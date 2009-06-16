# Ports collection makefile for:	Ruby/Bsearch
# Date created:			13 July 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bsearch
PORTVERSION=	1.5
CATEGORIES=	devel ruby
MASTER_SITES=	http://0xcc.net/ruby-bsearch/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A binary search library for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	bsearch.en.rd bsearch.ja.rd
DOCS_EN=	ChangeLog \
		${RUBY_RD_FILES:M*.en.rd} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.ja.rd} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsearch.rb ${RUBY_SITELIBDIR}/

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

.include <bsd.port.post.mk>
