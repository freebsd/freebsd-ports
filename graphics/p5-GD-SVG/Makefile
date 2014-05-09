# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	GD-SVG
PORTVERSION=	0.33
PORTREVISION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Seamlessly enable SVG output from scripts written using GD

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD \
		p5-SVG>=0:${PORTSDIR}/textproc/p5-SVG
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
