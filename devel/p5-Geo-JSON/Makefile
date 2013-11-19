# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-JSON
PORTVERSION=	0.005
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl OO interface for geojson

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-Role-Tiny>=0:${PORTSDIR}/devel/p5-Role-Tiny \
		p5-Type-Tiny>=0:${PORTSDIR}/devel/p5-Type-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-Load>=0:${PORTSDIR}/devel/p5-Class-Load \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Most>=0:${PORTSDIR}/devel/p5-Test-Most

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
