# New ports collection makefile for:	Ruby-Racc
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	racc
PORTVERSION=	1.3.10
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

.if !defined(RUNTIME)
RUN_DEPENDS=	${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime \
		${RUBY_SITELIBDIR}/strscan.rb:${PORTSDIR}/devel/ruby-strscan
.endif

USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

.if defined(RUNTIME)
CONFIGURE_ARGS=	--with=lib/raccrt,ext/cparse
.else
CONFIGURE_ARGS=	--with=bin/racc,lib/racc,ext/cscan
.endif

DOCS_EN=	changes.html command.html debug.html grammer.html \
		index.html parser.html usage.html
DOCS_JA=	changes.html command.html debug.html grammer.html \
		index.html parser.html usage.html
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y \
		hash.y lalr.y lists.y syntax.y yyerr.y

.if !defined(RUNTIME)
post-patch:
	${PERL} -i -pe '$$. == 1 && s,^#!\s*\S+,#!${RUBY},' \
		${WRKSRC}/misc/racc2y \
		${WRKSRC}/misc/y2racc
.endif

do-install:
.if defined(RUNTIME)
	${MKDIR} ${RUBY_SITELIBDIR}/racc
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/racc
.else
	${INSTALL_SCRIPT} ${WRKSRC}/bin/racc/racc \
		${WRKSRC}/misc/racc2y ${WRKSRC}/misc/y2racc ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/racc/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/racc/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} ${RUBY_DOCDIR}/racc/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} ${RUBY_DOCDIR}/racc/ja/
.endfor
.endif
.endif

.include <bsd.port.mk>
