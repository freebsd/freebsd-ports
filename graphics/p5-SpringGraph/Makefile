# ex:ts=8
# New ports collection makefile for:	graphics/p5-SpringGraph
# Date created:				25 November 2004
# Whom:					fernan@iib.unsam.edu.ar
#
# $FreeBSD$
#

PORTNAME=		SpringGraph
PORTVERSION=		0.05
CATEGORIES=		graphics perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	GraphViz/TEEJAY
PKGNAMEPREFIX=		p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Directed graph alternative to GraphViz

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD

MAN3=	SpringGraph.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
