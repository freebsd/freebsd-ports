# New ports collection makefile for:	Ruby/io-reactor
# Date created:		26 December 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	io-reactor
PORTVERSION=	0.0.6
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.deveiate.org/code/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	IO-Reactor-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby module that implements an asynchronous multiplexeded IO Reactor

USE_RUBY=	yes

NO_BUILD=	yes

DOCS=		ChangeLog README
EXAMPLES=	examples/*

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
