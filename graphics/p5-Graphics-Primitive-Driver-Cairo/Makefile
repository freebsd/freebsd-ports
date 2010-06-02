# Ports collection makefile for:	p5-Graphics-Primitive-Driver-Cairo
# Date created:			2008/08/30
# Whom:	      			chinsan
#
# $FreeBSD$
#

PORTNAME=	Graphics-Primitive-Driver-Cairo
PORTVERSION=	0.43
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cairo backend for Graphics::Primitive

RUN_DEPENDS=	p5-Cairo>=1.061:${PORTSDIR}/graphics/p5-Cairo \
		p5-Geometry-Primitive>=0.13:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Primitive>=0.45:${PORTSDIR}/graphics/p5-Graphics-Primitive \
		p5-Moose>=0.76:${PORTSDIR}/devel/p5-Moose \
		p5-Text-Flow>=0.01:${PORTSDIR}/textproc/p5-Text-Flow
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE= 5.8.0+

MAN3=		Graphics::Primitive::Driver::Cairo.3 \
  		Graphics::Primitive::Driver::Cairo::TextLayout.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
RUN_DEPENDS+=	p5-Math-Complex>=1.56:${PORTSDIR}/math/p5-Math-Complex
.endif

.include <bsd.port.post.mk>
