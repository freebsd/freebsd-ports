# New ports collection makefile for:	Ruby/IRC
# Date created:		19 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	irc
PORTVERSION=	0.13
CATEGORIES=	irc ruby
MASTER_SITES=	http://www.ueda.info.waseda.ac.jp/~igarashi/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	BUGS		ChangeLog	MANIFEST \
		NEWS		README		TODO
DOCS_JA=	MEMO.ja		README.ja

do-install:
	${INSTALL_DATA} ${WRKSRC}/localize.rb ${RUBY_SITELIBDIR}
	${MKDIR} ${RUBY_SITELIBDIR}/irc
	${INSTALL_DATA} ${WRKSRC}/irc/*.rb ${RUBY_SITELIBDIR}/irc/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/irc/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/irc/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/irc/ja/
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/* ${RUBY_DOCDIR}/irc/ja/
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/cpi
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/ja/cpi
	cd ${WRKSRC}/cpi && \
	for f in *.cpi; do ${INSTALL_DATA} $${f} ${RUBY_EXAMPLESDIR}/irc/cpi/; done; \
	for f in *.cpi.orig; do ${INSTALL_DATA} $${f} ${RUBY_EXAMPLESDIR}/irc/ja/cpi/$${f%.orig}; done
	${INSTALL_DATA} ${WRKSRC}/bot.rb ${RUBY_EXAMPLESDIR}/irc/
	${INSTALL_DATA} ${WRKSRC}/bot.rb.orig ${RUBY_EXAMPLESDIR}/irc/ja/bot.rb
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/log
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/ja/log
.endif

.include <bsd.port.mk>
