# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Devel-Leak-Cb
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Detect leaked callbacks

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-common-sense>=2:${PORTSDIR}/devel/p5-common-sense \
		p5-Devel-Declare>=0.005011:${PORTSDIR}/devel/p5-Devel-Declare
RUN_DEPENDS=	p5-Devel-Declare>=0.005011:${PORTSDIR}/devel/p5-Devel-Declare

USES=	perl5
USE_PERL5=	configure

.include <bsd.port.mk>
