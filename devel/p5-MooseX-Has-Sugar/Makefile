# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Has-Sugar
PORTVERSION=	0.05070421
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Sugar Syntax for moose has fields

BUILD_DEPENDS=	p5-Moose>=0.61:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Find-Lib>=0:${PORTSDIR}/devel/p5-Find-Lib \
		p5-Module-Build>=0.4002:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=		MooseX::Has::Sugar.3 \
		MooseX::Has::Sugar::Saccharin.3 \
		MooseX::Has::Sugar::Minimal.3

.include <bsd.port.mk>
