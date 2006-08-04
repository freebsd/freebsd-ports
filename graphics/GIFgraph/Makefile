# New ports collection makefile for:	p5-GIFgraph
# Date created:				Nov 9, 1998
# Whom:					laskavy@gambit.msk.su
#
# $FreeBSD$
#

PORTNAME=	GIFgraph
PORTVERSION=	1.20
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GIFgraph
PKGNAMEPREFIX=	p5-
DISTNAME=	GIFgraph-${PORTVERSION}

MAINTAINER=	ls@gambit.com.ru
COMMENT=	A Perl package to generate PNG charts

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

BROKEN=		does not build
DEPRECATED=	This module is simply a wrapper around GD::Graph and is deprecated.  One should simply use graphics/p5-GD-Graph
EXPIRATION_DATE=	2007-01-01

PERL_CONFIGURE=	YES

MAN3=		GIFgraph.3

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800 # inherited from graphics/p5-GD-Graph
IGNORE=	requires at least Perl 5.8.  Please install lang/perl.58 and try again
.endif

.include <bsd.port.post.mk>
