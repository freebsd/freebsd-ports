# Created by: jupengfei <jupengfei@gmail.com>
# $FreeBSD$

PORTNAME=	File-Map
PORTVERSION=	0.61
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:LEONT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Memory mapping made simple and safe

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PerlIO-Layers>=0:${PORTSDIR}/devel/p5-PerlIO-Layers \
		p5-Sub-Exporter-Progressive>=0.001.005:${PORTSDIR}/devel/p5-Sub-Exporter-Progressive
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Warnings>=0:${PORTSDIR}/devel/p5-Test-Warnings

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
