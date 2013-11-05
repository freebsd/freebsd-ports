# Created by: chinsan
# $FreeBSD$

PORTNAME=	Layout-Manager
PORTVERSION=	0.34
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GPHAT
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	2D Layout Management

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.54:${PORTSDIR}/devel/p5-Moose \
		p5-Module-Install>=0.64:${PORTSDIR}/devel/p5-Module-Install \
		p5-Geometry-Primitive>=0.13:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Primitive>=0.34:${PORTSDIR}/graphics/p5-Graphics-Primitive
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
