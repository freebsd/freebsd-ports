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
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby \
		${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER}/amstd/info.rb:${PORTSDIR}/devel/ruby-amstd

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

MODULES=	facade.rb format.rb info.rb libracc.rb raccp.rb raccs.rb \
		register.rb state.rb
MODULES_RT=	parser.rb
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
	${INSTALL_SCRIPT} ${WRKSRC}/bin/racc/racc ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/racc
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/racc/${f} \
		${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/racc/
.endfor
.for f in ${MODULES_RT}
	${INSTALL_DATA} ${WRKSRC}/lib/raccrt/${f} \
		${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/racc/
.endfor
	${MKDIR} ${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}/racc
	${INSTALL_DATA} ${WRKSRC}/ext/cparse/cparse.so \
		${PREFIX}/lib/ruby/site_ruby/${RUBY_VER}/${RUBY_ARCH}/racc/
	${MKDIR} ${PREFIX}/share/examples/ruby/racc
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${PREFIX}/share/examples/ruby/racc/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/racc/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc.en/${f} ${PREFIX}/share/doc/ruby/racc/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc.ja/${f} ${PREFIX}/share/doc/ruby/racc/ja/
.endfor
.endif

.include <bsd.port.mk>
