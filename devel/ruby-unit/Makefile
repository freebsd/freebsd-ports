# New ports collection makefile for:	RubyUnit
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	unit
PORTVERSION=	0.5.5
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage1.nifty.com/markey/ruby/rubyunit/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_RDTOOL=	yes

RUBY_MODNAME=	runit

RUBY_SHEBANG_FILES=	${WRKSRC}/bin/c2t.rb	\
			${WRKSRC}/bin/runtest.rb

BINS=		c2t		runtest
DOCS=		ChangeLog	README		ToDo
DOCS_JA=	README.ja

do-build:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} makehtml.rb
.endif

do-install:
	@cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${RUBY} install.rb
.for f in ${BINS}
	${LN} -sf ${f}.rb ${PREFIX}/bin/${f}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/ ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
	${CP} -R ${WRKSRC}/doc_en/ ${RUBY_MODDOCDIR}/
	${CP} -R ${WRKSRC}/doc_ja/ ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
