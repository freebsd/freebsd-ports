# New ports collection makefile for:	rbnamazu
# Date created:		18 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbnamazu
PORTVERSION=	0.4
CATEGORIES=	japanese textproc ruby
MASTER_SITES=	ftp://ftp.namazu.org/pub/namazu/ruby/
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A client of the "Namazu" full-text search engine written in Ruby

USE_RUBY=	yes
USE_RUBY_FEATURES=	optparse

NO_BUILD=	yes

MODULES=	rbnamazu.rb nmzqr.rb nmzqr.tab.rb nmzdoc.rb
RD_DOCS=	

RUBY_RD_FILES=	rbnamazu.rd.ja rbnamazu.rd.en

DOCS_EN=	${RUBY_RD_FILES:M*.rd.en} \
		${RUBY_RD_HTML_FILES:M*.en.html}
DOCS_JA=	${RUBY_RD_FILES:M*.rd.ja} \
		${RUBY_RD_HTML_FILES:M*.ja.html}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/namazu.rb ${PREFIX}/bin/
	${LN} -sf namazu.rb ${PREFIX}/bin/rbnamazu
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
