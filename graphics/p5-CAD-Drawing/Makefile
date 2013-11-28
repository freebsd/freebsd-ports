# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CAD-Drawing
PORTVERSION=	0.26
PORTREVISION=	8
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Methods to create, load, and save vector graphics

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CAD-Calc>=0:${PORTSDIR}/math/p5-CAD-Calc \
		p5-Math-Geometry-Planar>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar \
		p5-Math-MatrixReal>=0:${PORTSDIR}/math/p5-Math-MatrixReal \
		p5-Math-Vec>=0:${PORTSDIR}/math/p5-Math-Vec \
		p5-Stream>=0:${PORTSDIR}/devel/p5-Stream \
		${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
