# New ports collection makefile for:	p5-Test-Mini-Unit
# Date created:		2011-01-13
# Whom:			Kurt Lidl <kurt.lidl@cello.com>
#
# $FreeBSD$
#

PORTNAME=	Test-Mini-Unit
PORTVERSION=	v1.0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN/../../authors/id/P/PV/PVANDE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kurt.lidl@cello.com
COMMENT=	Declarative syntactic sugar for Test::Mini

BUILD_DEPENDS=	p5-Devel-Declare>=0.6.0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Test-Mini>=v1.1.3:${PORTSDIR}/devel/p5-Test-Mini

PERL_CONFIGURE=	yes

MAN3=	Test::Mini::README.3 \
	Test::Mini::Unit.3

.include <bsd.port.mk>
