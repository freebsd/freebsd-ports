# Ports collection makefile for:	Ruby/Romkan
# Date created:			1 May 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	romkan
PORTVERSION=	0.4
CATEGORIES=	japanese converters ruby
MASTER_SITES=	http://0xcc.net/ruby-romkan/
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Romaji <-> Kana conversion library for Ruby

USE_RUBY=	yes

NO_BUILD=	yes

EXAMPLES_JA=	test.rb test.sh

RUBY_RD_FILES=	romkan.en.rd romkan.ja.rd

DOCS_EN=	ChangeLog \
		${RUBY_RD_FILES:M*.en.rd} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.ja.rd} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/romkan.rb ${RUBY_SITELIBDIR}/

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
.for f in ${EXAMPLES_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
