# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Image-Base-SVG
PORTVERSION=	4
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SVG image file output

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Image-Base>=0:graphics/p5-Image-Base \
		p5-SVG>=2.38:textproc/p5-SVG \
		p5-SVG-Parser>=0:textproc/p5-SVG-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e 's|Image-Base-SVG|Image::Base::SVG|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
