# New ports collection makefile for:	Ruby-textbuf
# Date created:		19 Jan 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	textbuf
PORTVERSION=	0.3.8
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.loveruby.net/archive/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Gapped text buffer extention for Ruby

USE_RUBY=	yes
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

DOCS_EN=	README.en
DOCS_JA=	README.ja

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/stest.rb ${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/test.rb ${RUBY_MODEXAMPLESDIR}/ja/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
