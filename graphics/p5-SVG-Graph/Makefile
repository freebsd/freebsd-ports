# vim:ts=8
# New ports collection makefile for:	p5-SVG-Graph
# Date created:				25 November 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	SVG-Graph
PORTVERSION=	0.01
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SVG
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Visualize your data in Scalable Vector Graphics (SVG) format

BUILD_DEPENDS=	${SITE_PERL}/SVG.pm:${PORTSDIR}/textproc/p5-SVG \
		${SITE_PERL}/Statistics/Descriptive.pm:${PORTSDIR}/math/p5-Statistics-Descriptive \
		${SITE_PERL}/Tree/DAG_Node.pm:${PORTSDIR}/devel/p5-Tree-DAG_Node \
		${SITE_PERL}/Math/Spline.pm:${PORTSDIR}/math/p5-Math-Spline \
		${SITE_PERL}/Math/Derivative.pm:${PORTSDIR}/math/p5-Math-Derivative

PERL_CONFIGURE=	yes

MAN3=		SVG::Graph.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		This port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
