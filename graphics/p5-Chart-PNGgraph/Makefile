# New ports collection makefile for:	p5-Chart-PNGgraph
# Date Created:		15 December 1999
# Whom:			Garrett Wollman <wollman@lcs.mit.edu>
#
# $FreeBSD$
#

PORTNAME=	Chart-PNGgraph
PORTVERSION=	1.21
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Chart
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A Perl module for generating presentation graphics (i.e., charts)

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=		Chart::PNGgraph.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
