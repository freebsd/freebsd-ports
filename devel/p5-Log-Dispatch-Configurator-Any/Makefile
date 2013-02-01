# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Configurator-Any
PORTVERSION=	1.122.640
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Configurator implementation with Config::Any

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Any>=0.15:${PORTSDIR}/devel/p5-Config-Any \
		p5-Log-Dispatch>=2.23:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Config>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Config
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-Test-Pod>=1.14:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::Configurator::Any.3

.include <bsd.port.mk>
