# Created by: Kurt Lidl <kurt.lidl@cello.com>
# $FreeBSD$

PORTNAME=	Test-Mini-Unit
PORTVERSION=	v1.0.3
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PVANDE
PKGNAMEPREFIX=	p5-

MAINTAINER=	kurt.lidl@cello.com
COMMENT=	Declarative syntactic sugar for Test::Mini

BUILD_DEPENDS=	p5-Devel-Declare>=0.6.0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Test-Mini>=v1.1.3:${PORTSDIR}/devel/p5-Test-Mini

USES=		perl5
USE_PERL5=	configure

MAN3=	Test::Mini::README.3 \
	Test::Mini::Unit.3

NO_STAGE=	yes
.include <bsd.port.mk>
