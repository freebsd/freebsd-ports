# New ports collection makefile for:	Ruby/RBTree
# Date created:		12 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbtree
PORTVERSION=	0.1.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.geocities.co.jp/SiliconValley-PaloAlto/3388/rbtree/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An implementation of Red-Black Tree for Ruby

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

# MIT license
DOCS=		ChangeLog LICENSE README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
