# New ports collection makefile for:	Ruby-amstd
# Date created:		7 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	amstd
PORTVERSION=	1.9.6
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.xdsl.ne.jp/Cd/aamine/soft/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	README.en
DOCS_JA=	README.ja amstd-ja.rd
MODULES=	bench.rb \
		bug.rb \
		collfrom.rb \
		constdef.rb \
		dispatch.rb \
		errutil.rb \
		extmod.rb \
		fileutils.rb \
		futils.rb \
		gconst.rb \
		getdep.rb \
		info.rb \
		must.rb \
		pipeline.rb \
		rbparams.rb \
		recycle.rb \
		rubyemu.rb \
		strquote.rb \
		symbol.rb \
		timer.rb \
		to_s.rb \
		version.rb

do-install:
	${MKDIR} ${RUBY_SITELIBDIR}/amstd
.for f in ${MODULES}
	${INSTALL_DATA} ${WRKSRC}/lib/amstd/${f} \
			${RUBY_SITELIBDIR}/amstd/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/amstd/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/amstd/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/amstd/ja/
.endfor
.endif

.include <bsd.port.mk>
