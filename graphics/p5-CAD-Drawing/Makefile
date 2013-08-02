# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	CAD-Drawing
PORTVERSION=	0.26
PORTREVISION=	7
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Methods to create, load, and save vector graphics

RUN_DEPENDS=	p5-Math-Vec>=0:${PORTSDIR}/math/p5-Math-Vec \
		p5-CAD-Calc>=0:${PORTSDIR}/math/p5-CAD-Calc \
		p5-MatrixReal>=0:${PORTSDIR}/math/p5-MatrixReal \
		convert:${PORTSDIR}/graphics/ImageMagick \
		p5-Stream>=0:${PORTSDIR}/devel/p5-Stream \
		p5-Math-Geometry-Planar>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAN3=	CAD::Drawing.3 \
	CAD::Drawing::Calculate.3 \
	CAD::Drawing::Calculate::Finite.3 \
	CAD::Drawing::Defined.3 \
	CAD::Drawing::IO.3 \
	CAD::Drawing::IO::Circ.3 \
	CAD::Drawing::IO::Compressed.3 \
	CAD::Drawing::IO::FlatYAML.3 \
	CAD::Drawing::IO::Split.3 \
	CAD::Drawing::Manipulate.3 \
	CAD::Drawing::Manipulate::Graphics.3 \
	CAD::Drawing::Manipulate::Transform.3

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
