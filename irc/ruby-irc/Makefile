# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	irc
PORTVERSION=	0.14
CATEGORIES=	irc ruby
MASTER_SITES=	http://ibiblio.lsu.edu/main/pub/languages/ruby/contrib/ \
		ftp://ftp.tms.ru/pub/ruby/libraries/irc/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	IRC client framework for Ruby

USE_RUBY=	yes

NO_BUILD=	yes
NO_ARCH=	yes

DOCS_EN=	BUGS		ChangeLog	MANIFEST \
		NEWS		README		TODO
DOCS_JA=	MEMO.ja		README.ja	doc.ja/*

OPTIONS_DEFINE=	DOCS

DEPRECATED=		Upstream no longer active
EXPIRATION_DATE=	2017-01-28

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/localize.rb ${STAGEDIR}${RUBY_SITELIBDIR}
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/irc
	${INSTALL_DATA} ${WRKSRC}/irc/*.rb ${STAGEDIR}${RUBY_SITELIBDIR}/irc/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/cpi
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/ja/cpi
	${INSTALL_DATA} ${WRKSRC}/cpi/*.cpi ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/cpi/
	${INSTALL_DATA} ${WRKSRC}/cpi.ja/*.cpi ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/ja/cpi/
	${INSTALL_DATA} ${WRKSRC}/bot.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/bot.ja.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/ja/bot.rb
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/log
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/ja/log

.include <bsd.port.mk>
