# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	GD-SVG
PORTVERSION=	0.33
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Seamlessly enable SVG output from scripts written using GD

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD \
		p5-SVG>=0:textproc/p5-SVG

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
