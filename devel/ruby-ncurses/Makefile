# New ports collection makefile for:	ncurses-ruby
# Date created:		7 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ncurses
PORTVERSION=	0.9
CATEGORIES=	devel ruby
MASTER_SITES=	http://download.berlios.de/ncurses-ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to ncurses

USE_BZIP2=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		Changes README THANKS TODO

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
