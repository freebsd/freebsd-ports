# New ports collection makefile for:	Ruby-Racc
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	racc
PORTVERSION=	1.2.3
CATEGORIES=	devel ruby
MASTER_SITES=	http://www1.u-netsurf.ne.jp/~brew/mine/soft/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${RUBY_SITELIBDIR}/amstd/info.rb:${PORTSDIR}/devel/ruby-amstd

.if !defined(RUNTIME)
RUN_DEPENDS+=	${RUBY_SITELIBDIR}/racc/parser.rb:${PORTSDIR}/devel/ruby-racc-runtime
.endif[

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY?=		${LOCALBASE}/bin/ruby
RUBY_VER?=	1.4
RUBY_ARCH?=	${ARCH}-freebsd${OSREL}

RUBY_SITELIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}
RUBY_SITEARCHLIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}

MODULES=	facade.rb format.rb grammer.rb info.rb iset.rb \
		libracc.rb raccp.rb raccs.rb state.rb
MODULES_RT=	parser.rb
DOCS_EN=	changes.html command.html debug.html grammer.html \
		index.html usage.html
DOCS_JA=	changes.html command.html debug.html grammer.html \
		index.html parser.html usage.html
EXAMPLES=	calc-ja.y calc.y conflict.y lalr.y syntax.y yyerr.y

.if !defined(RUNTIME)
post-patch:
	${RM} -rf ${WRKSRC}/ext
	${PERL} -i -pe '$$. == 1 && s,^#!\s*\S+,#!${RUBY},' \
		${WRKSRC}/misc/racc2y \
		${WRKSRC}/misc/y2racc
.endif

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} setup.rb config

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${RUBY} setup.rb setup

do-install:
.if defined(RUNTIME)
	${MKDIR} ${RUBY_SITELIBDIR}/racc
.for f in ${MODULES_RT}
	${INSTALL_DATA} ${WRKSRC}/lib/raccrt/${f} ${RUBY_SITELIBDIR}/racc/
.endfor
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/racc
	${INSTALL_DATA} ${WRKSRC}/ext/cparse/cparse.so ${RUBY_SITEARCHLIBDIR}/racc/
.else
	${INSTALL_SCRIPT} ${WRKSRC}/bin/racc/racc \
		${WRKSRC}/misc/racc2y ${WRKSRC}/misc/y2racc ${PREFIX}/bin/
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/racc/${f} ${RUBY_SITELIBDIR}/racc/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/ruby/racc/
.endfor
	${MKDIR} ${PREFIX}/share/doc/ruby/racc/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} ${PREFIX}/share/doc/ruby/racc/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} ${PREFIX}/share/doc/ruby/racc/ja/
.endfor
.endif
.endif

.include <bsd.port.mk>
