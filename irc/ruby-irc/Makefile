# New ports collection makefile for:	Ruby/IRC
# Date created:		19 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	irc
PORTVERSION=	0.14
CATEGORIES=	irc ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	IRC client framework for Ruby

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
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/cpi
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja/cpi
	${INSTALL_DATA} ${WRKSRC}/cpi/*.cpi ${RUBY_MODEXAMPLESDIR}/cpi/
	${INSTALL_DATA} ${WRKSRC}/cpi.ja/*.cpi ${RUBY_MODEXAMPLESDIR}/ja/cpi/
	${INSTALL_DATA} ${WRKSRC}/bot.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/bot.ja.rb ${RUBY_MODEXAMPLESDIR}/ja/bot.rb
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/log
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja/log
.endif

.include <bsd.port.mk>
