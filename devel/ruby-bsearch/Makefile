# Ports collection makefile for:	Ruby/Bsearch
# Date created:			13 July 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	bsearch
PORTVERSION=	1.5
CATEGORIES=	devel ruby
MASTER_SITES=	http://namazu.org/~satoru/ruby-bsearch/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

DOCS_EN=	ChangeLog bsearch.en.html bsearch.en.rd
DOCS_JA=	bsearch.ja.html bsearch.ja.rd

do-build:
.if !defined(NOPORTDOCS)
.for f in bsearch.en.rd bsearch.ja.rd
	@cd ${WRKSRC}; \
	${RUBY_RD2} ${f} > ${f:R}.html
.endfor
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bsearch.rb ${RUBY_SITELIBDIR}/
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
