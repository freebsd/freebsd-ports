# New ports collection makefile for:	Ruby/AVL
# Date created:		22 August 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	avl
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES+=	devel ruby
MASTER_SITES=	http://bocks.psych.purdue.edu/~pizman/avl/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	AVL tree class for Ruby

BUILD_DEPENDS=	${LOCALBASE}/lib/libavl.a:${PORTSDIR}/devel/libavl

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

EXAMPLES=	Dussel.txt	getwords.rb \
		test.rb		test2.rb \
		test3.rb	test4.rb
DOCS=		README

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not build on amd64 (needs to link against shared libraries)
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
