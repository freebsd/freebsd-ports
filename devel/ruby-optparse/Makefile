# New ports collection makefile for:    Ruby-OptionParser
# Date created:         7 Aug 2000
# Whom:                 Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	optparse
PORTVERSION=	0.7.5
CATEGORIES=	devel	# ruby
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/
PKGNAMEPREFIX=	ruby-
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	ruby:${PORTSDIR}/lang/ruby
RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

NO_BUILD=	yes

PLIST_SUB=	RUBY_VER="${RUBY_VER}" RUBY_ARCH="${RUBY_ARCH}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4
RUBY_ARCH=	${ARCH}-freebsd${OSREL}

do-install:
	${MKDIR} ${PREFIX}/lib/ruby/site_ruby/optparse
.for f in optparse.rb optparse/shellwords.rb optparse/time.rb
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/lib/ruby/site_ruby/${f}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/ruby/optparse/ja
	${MKDIR} ${PREFIX}/share/doc/ruby/optparse/ja
.for f in optparse.rlog
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/optparse/
.endfor
.for f in optparse.ja.rd
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/ruby/optparse/ja/
.endfor
.for f in cmd-ls.rb cmd.rb getopts.test.en opttest.rb
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/ruby/optparse/
.endfor
.for f in getopts.test
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/examples/ruby/optparse/ja
.endfor
.endif

.include <bsd.port.mk>
