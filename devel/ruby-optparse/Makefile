# New ports collection makefile for:	Ruby-OptionParser
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	optparse
PORTVERSION=	0.7.5
CATEGORIES=	devel ruby
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/optparse
.for f in optparse.rb optparse/shellwords.rb optparse/time.rb
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_SITELIBDIR}/${f}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/optparse/ja
	${MKDIR} ${RUBY_DOCDIR}/optparse/ja
.for f in optparse.rlog
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/optparse/
.endfor
.for f in optparse.ja.rd
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/optparse/ja/
.endfor
.for f in cmd-ls.rb cmd.rb getopts.test.en opttest.rb
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/optparse/
.endfor
.for f in getopts.test
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/optparse/ja
.endfor
.endif

.include <bsd.port.mk>
