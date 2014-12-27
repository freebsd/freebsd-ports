# Created by: ijliao
# $FreeBSD$

PORTNAME=	Chart-Graph
PORTVERSION=	3.2
PORTREVISION=	9
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl extension for a front-end to gnuplot, XRT, and Xmgrace

LICENSE=	GPLv2

RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot \
		xmgrace:${PORTSDIR}/math/grace \
		ppmtogif:${PORTSDIR}/graphics/netpbm

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
