# $FreeBSD$

PORTNAME=	MooX-Options
PORTVERSION=	4.003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	espen@tagestad.no
COMMENT=	Option keywords to your object (Mo/Moo/Moose)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Data-Record>=0:${PORTSDIR}/devel/p5-Data-Record \
		p5-Getopt-Long-Descriptive>=0.091:${PORTSDIR}/devel/p5-Getopt-Long-Descriptive \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-Module-Metadata>=1.000019:${PORTSDIR}/devel/p5-Module-Metadata \
		p5-Moo>=1.003001:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-ConfigFromFile>=0:${PORTSDIR}/devel/p5-MooX-ConfigFromFile \
		p5-Path-Class>=0.32:${PORTSDIR}/devel/p5-Path-Class \
		p5-Regexp-Common>=0:${PORTSDIR}/textproc/p5-Regexp-Common \
		p5-Term-Size-Any>=0:${PORTSDIR}/devel/p5-Term-Size-Any \
		p5-Text-WrapI18N>=0:${PORTSDIR}/textproc/p5-Text-WrapI18N
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-Mo>=0:${PORTSDIR}/devel/p5-Mo \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Role-Tiny>=0:${PORTSDIR}/devel/p5-Role-Tiny \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Trap>=0:${PORTSDIR}/devel/p5-Test-Trap \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-namespace-clean>=0:${PORTSDIR}/devel/p5-namespace-clean

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
