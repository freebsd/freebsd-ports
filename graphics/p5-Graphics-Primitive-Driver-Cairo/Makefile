# Ports collection makefile for:	p5-Graphics-Primitive-Driver-Cairo
# Date created:			2008/08/30
# Whom:	      			chinsan
#
# $FreeBSD$
#

PORTNAME=	Graphics-Primitive-Driver-Cairo
PORTVERSION=	0.44
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cairo backend for Graphics::Primitive

BUILD_DEPENDS=	p5-Cairo>=0:${PORTSDIR}/graphics/p5-Cairo \
		p5-Geometry-Primitive>=0:${PORTSDIR}/graphics/p5-Geometry-Primitive \
		p5-Graphics-Primitive>=0:${PORTSDIR}/graphics/p5-Graphics-Primitive \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Text-Flow>=0:${PORTSDIR}/textproc/p5-Text-Flow
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Graphics-Color>=0:${PORTSDIR}/graphics/p5-Graphics-Color

PERL_CONFIGURE=	yes

MAN3=		Graphics::Primitive::Driver::Cairo.3 \
  		Graphics::Primitive::Driver::Cairo::TextLayout.3

.include <bsd.port.mk>
