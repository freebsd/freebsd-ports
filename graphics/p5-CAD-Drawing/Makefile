# New ports collection makefile for:	CAD-Drawing
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CAD-Drawing
PORTVERSION=	0.26
PORTREVISION=	7
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Methods to create, load, and save vector graphics

RUN_DEPENDS=	p5-Math-Vec>=0:${PORTSDIR}/math/p5-Math-Vec \
		p5-CAD-Calc>=0:${PORTSDIR}/math/p5-CAD-Calc \
		p5-MatrixReal>=0:${PORTSDIR}/math/p5-MatrixReal \
		ImageMagick>=0:${PORTSDIR}/graphics/ImageMagick \
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

PERL_MODBUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
