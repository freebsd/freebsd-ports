# New ports collection makefile for:    Ruby-Racc
# Date created:         7 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	racc
PORTVERSION=	1.2.1
CATEGORIES=	devel	# ruby
MASTER_SITES=	http://www1.u-netsurf.ne.jp/~brew/mine/soft/
PKGNAMEPREFIX=	ruby-

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

DOCS_EN=	changes.html command.html debug.html grammer.html \
		index.html usage.html
DOCS_JA=	changes.html command.html debug.html grammer.html \
		index.html parser.html usage.html
EXAMPLES=	calc.y calc2-ja.y compile.rb

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} setup.rb config

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${RUBY} setup.rb setup

do-install:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${RUBY} setup.rb install
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/racc/examples
	${MKDIR} ${PREFIX}/share/doc/ruby/racc/ja
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/doc/ruby/racc/examples/
.endfor
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} ${PREFIX}/share/doc/ruby/racc/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} ${PREFIX}/share/doc/ruby/racc/ja/
.endfor
.endif

.include <bsd.port.mk>
