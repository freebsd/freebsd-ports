# New ports collection makefile for:	Ruby-OptionParser
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	optparse
PORTVERSION=	0.8
CATEGORIES=	devel ruby
MASTER_SITES=	http://member.nifty.ne.jp/nokada/archive/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	ChangeLog.html \
		README.en \
		optparse.en.rd \
		optparse.html \
		optparse.rlog \
		rmi.html
DOCS_JA=	FIRSTSTEP.ja.html \
		FIRSTSTEP.ja.rd \
		README.ja \
		optparse.ja.html \
		optparse.ja.rd

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/optparse.rb ${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/optparse/*.rb${f} ${RUBY_SITELIBDIR}/${PORTNAME}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}/ja
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.for f in cmd-ls.rb cmd.rb getopts.test.en opttest.rb
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
.for f in getopts.test
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/ja
.endfor
.endif

.include <bsd.port.mk>
