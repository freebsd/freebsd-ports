# Created by: wen@FreeBSD.org
# $FreeBSD$

PORTNAME=	Bio-Graphics
PORTVERSION=	2.39
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate GD Images of Bio::Seq Objects

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Bio-SCF>=1.01:biology/p5-Bio-SCF \
		p5-GD>=2.30:graphics/p5-GD \
		p5-GD-SVG>=0.32:graphics/p5-GD-SVG \
		p5-Statistics-Descriptive>=2.6:math/p5-Statistics-Descriptive \
		p5-bioperl>=1.6.0:biology/p5-bioperl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
