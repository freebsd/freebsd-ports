# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Has-Sugar
PORTVERSION=	1.000000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sugar Syntax for moose has fields

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.61:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Find-Lib>=0:${PORTSDIR}/devel/p5-Find-Lib \
		p5-Module-Build>=0.4002:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
