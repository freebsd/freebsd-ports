# New ports collection makefile for:	graphics/p5-Imager-Graph
# Date created:				11 Feb 2005
# Whom:					Yuan-Chung Hsiao <ychsiao@ychsiao.org>
#
# $FreeBSD$
#

PORTNAME=	Imager-Graph
PORTVERSION=	0.03
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/T/TO/TONYC
PKGNAMEPREFIX=	p5-

MAINTAINER=	ychsiao@ychsiao.org
COMMENT=	Perl extension for producing Graphs using the Imager library

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Imager::Graph.3 Imager::Graph::Util.3 Imager::Graph::Pie.3

.include <bsd.port.mk>
