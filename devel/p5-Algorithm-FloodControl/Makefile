# Created by: Andrey <gugu@zoo.rambler.ru>
# $FreeBSD$

PORTNAME=	Algorithm-FloodControl
PORTVERSION=	2.001000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Robot protection

BUILD_DEPENDS=	p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Module-Load>=0:${PORTSDIR}/devel/p5-Module-Load \
		p5-Cache-FastMmap>=0:${PORTSDIR}/devel/p5-Cache-FastMmap \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Algorithm::FloodControl.3 Algorithm::FloodControl::Backend::Cache::Memcached.3 \
		Algorithm::FloodControl::Backend::Cache::Memcached::Fast.3 \
		Algorithm::FloodControl::Backend::Cache::FastMmap.3 \
		Algorithm::FloodControl::Backend.3

.include <bsd.port.mk>
