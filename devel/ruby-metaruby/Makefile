# New ports collection makefile for:	MetaRuby
# Date created:		8 March 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	metaruby
PORTVERSION=	0.7
CATEGORIES=	devel ruby
MASTER_SITES=	http://artengine.ca/matju/MetaRuby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	MetaRuby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A reimplementations of some Ruby parts in Ruby, Perl's tie equivalent

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

DOCS=		ChangeLog	Overview	TODO		doc/*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
