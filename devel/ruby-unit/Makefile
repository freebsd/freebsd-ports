# New ports collection makefile for:	RubyUnit
# Date created:		22 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	runit
PORTVERSION=	0.2.7
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage1.nifty.com/markey/ruby/rubyunit/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/^r/ruby/}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
.if !defined(NOPORTDOCS)
USE_RUBY_RD=	yes
.endif

RUBY_SHEBANG_FILES=	${WRKSRC}/bin/c2t.rb	\
			${WRKSRC}/bin/runtest.rb

BINS=		c2t		runtest
DOCS=		ChangeLog	README		ToDo

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
	${MKDIR} ${RUBY_EXAMPLESDIR}/runit
	${CP} -R ${WRKSRC}/sample/ ${RUBY_EXAMPLESDIR}/runit/
	${MKDIR} ${RUBY_DOCDIR}/runit
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/runit/
.endfor
	${CP} -R ${WRKSRC}/doc_en/ ${RUBY_DOCDIR}/runit/
.endif

.include <bsd.port.mk>
