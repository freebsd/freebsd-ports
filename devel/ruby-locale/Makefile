# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	locale
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.jp.vim.org/pub/distfiles/ruby/ \
		http://www.mmnt.net/db/0/8/ftp.jp.vim.org/pub/distfiles/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple Ruby module that provides setlocale(3)

CONFLICTS=	${PKGNAMEPREFIX}locale2-[0-9]*

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

OPTIONS_DEFINE=	DOCS EXAMPLES

DEPRECATED=	No longer useful
EXPIRATION_DATE=	2017-01-28

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${RUBY_MODDOCDIR}/
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/

.include <bsd.port.mk>
