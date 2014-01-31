# Created by: Peter Vereshagin <peter@vereshagin.org>
# $FreeBSD$

PORTNAME=	Sub-Alias
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	peter@vereshagin.org
COMMENT=	Simple subroutine alias

LICENSE=	MIT

BUILD_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Devel-BeginLift>=0:${PORTSDIR}/devel/p5-Devel-BeginLift
RUN_DEPENDS=	p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-Devel-Declare>=0:${PORTSDIR}/devel/p5-Devel-Declare \
		p5-Devel-BeginLift>=0:${PORTSDIR}/devel/p5-Devel-BeginLift

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
