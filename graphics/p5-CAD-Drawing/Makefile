# New ports collection makefile for:	CAD-Drawing
# Date created:				21 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CAD-Drawing
PORTVERSION=	0.26
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Methods to create, load, and save vector graphics

RUN_DEPENDS=	${SITE_PERL}/Math/Vec.pm:${PORTSDIR}/math/p5-Math-Vec \
		${SITE_PERL}/CAD/Calc.pm:${PORTSDIR}/math/p5-CAD-Calc \
		${SITE_PERL}/Math/MatrixReal.pm:${PORTSDIR}/math/p5-MatrixReal \
		${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
		${SITE_PERL}/Stream/FileInputStream.pm:${PORTSDIR}/devel/p5-Stream \
		${SITE_PERL}/Math/Geometry/Planar.pm:${PORTSDIR}/math/p5-Math-Geometry-Planar
BUILD_DEPENDS=	${RUN_DEPENDS}

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
