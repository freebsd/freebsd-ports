# New ports collection makefile for:	Ruby/IRC
# Date created:		19 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	irc
PORTVERSION=	0.14
CATEGORIES=	irc ruby
MASTER_SITES=	http://www.ruby-lang.org/~knu/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

DOCS_EN=	BUGS		ChangeLog	MANIFEST \
		NEWS		README		TODO
DOCS_JA=	MEMO.ja		README.ja	doc.ja/*

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
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/cpi
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/ja/cpi
	${INSTALL_DATA} ${WRKSRC}/cpi/*.cpi ${RUBY_EXAMPLESDIR}/irc/cpi/
	${INSTALL_DATA} ${WRKSRC}/cpi.ja/*.cpi ${RUBY_EXAMPLESDIR}/irc/ja/cpi/
	${INSTALL_DATA} ${WRKSRC}/bot.rb ${RUBY_EXAMPLESDIR}/irc/
	${INSTALL_DATA} ${WRKSRC}/bot.ja.rb ${RUBY_EXAMPLESDIR}/irc/ja/bot.rb
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/log
	${MKDIR} ${RUBY_EXAMPLESDIR}/irc/ja/log
.endif

.include <bsd.port.mk>
