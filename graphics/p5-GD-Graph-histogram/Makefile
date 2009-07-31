# New ports collection makefile for:	p5-GD-Graph-histogram
# Date created:				6 March 2009
# Whom:	      				Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	GD-Graph-histogram
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/W/WH/WHIZDOG
PKGNAMEPREFIX=	p5-
DISTNAME=	GDGraph-histogram-${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Histogram plotting module for perl5

BUILD_DEPENDS=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph \
		${SITE_PERL}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		GD::Graph::histogram.3

.include <bsd.port.mk>
