# ex:ts=8
# Ports collection makefile for:	p5-Chart-Graph
# Date Created:			Aug 30, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Chart-Graph
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Chart
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for a front-end to gnuplot, XRT, and Xmgrace

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		xmgrace:${PORTSDIR}/math/grace \
		ppmtogif:${PORTSDIR}/graphics/netpbm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
USE_REINPLACE=	yes
PERL_CONFIGURE=	yes

MAN3=	Chart::Graph.3 \
	Chart::Graph::Gnuplot.3 \
	Chart::Graph::Xmgrace.3 \
	Chart::Graph::Xrt2d.3 \
	Chart::Graph::Xrt3d.3

post-patch:
	@${REINPLACE_CMD} -e "s,%%X11BASE%%,${X11BASE}," ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
