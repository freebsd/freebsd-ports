# New ports collection makefile for:	p5-chart
# Date Created:		8 April 1998
# Whom:			Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Chart
PORTVERSION=	2.4.2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A perl5 interface to build chart graphics

RUN_DEPENDS=	p5-GD>=2:${PORTSDIR}/graphics/p5-GD
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Chart.3

.include <bsd.port.mk>
