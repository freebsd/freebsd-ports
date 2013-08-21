# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Astro-Flux
PORTVERSION=	0.01
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Class for handling astronomical flux quantities

BUILD_DEPENDS=	p5-Astro-WaveBand>=0:${PORTSDIR}/astro/p5-Astro-WaveBand \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-Misc-Quality>=0:${PORTSDIR}/astro/p5-Misc-Quality \
		p5-Number-Uncertainty>=0:${PORTSDIR}/math/p5-Number-Uncertainty
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		Astro::Flux.3 \
		Astro::FluxColor.3 \
		Astro::Fluxes.3

.include <bsd.port.mk>
