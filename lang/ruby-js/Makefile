# New ports collection makefile for:	Ruby/JS
# Date created:		25 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	js
PORTVERSION=	0.0.2
CATEGORIES=	lang ruby
MASTER_SITES=	http://www.ruby-lang.org/~tamura/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby binding to NJS JavaScript Interpreter

LIB_DEPENDS=	js.0:${PORTSDIR}/lang/njs

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

EXAMPLES=	html_ssi_lua.rb test_*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/rubylua.txt ${RUBY_MODDOCDIR}/
.endif

.include <bsd.port.mk>
