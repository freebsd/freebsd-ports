# $FreeBSD$

PORTNAME=	TAP-SimpleOutput
PORTVERSION=	0.002
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	TAP
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Simple closure-driven TAP generator

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-Sub-Exporter-Progressive>=0:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
