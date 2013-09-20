# $FreeBSD$

PORTNAME=	MooX-Options
PORTVERSION=	3.77
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Option keywords to your object (Mo/Moo/Moose)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Runtime>=0.012:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moo>=0.091010:${PORTSDIR}/devel/p5-Moo \
		p5-Data-Record>=0.02:${PORTSDIR}/devel/p5-Data-Record \
		p5-Module-Load-Conditional>=0.54:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Module-Metadata>=1.000011:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-namespace-clean>=0.24:${PORTSDIR}/devel/p5-namespace-clean \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap
RUN_DEPENDS=	p5-Module-Runtime>=0.012:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Moo>=0.091010:${PORTSDIR}/devel/p5-Moo \
		p5-Data-Record>=0.02:${PORTSDIR}/devel/p5-Data-Record \
		p5-Module-Load-Conditional>=0.54:${PORTSDIR}/devel/p5-Module-Load-Conditional \
		p5-Module-Metadata>=1.000011:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-namespace-clean>=0.24:${PORTSDIR}/devel/p5-namespace-clean \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Getopt-Long-Descriptive>=0.093:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common

USES=		perl5
USE_PERL5=	modbuild

MAN3=		MooX::Options.3 \
		MooX::Options::Role.3

NO_STAGE=	yes
.include <bsd.port.mk>
