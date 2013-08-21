# New ports collection makefile for:	p5-Image-Base-SVG
# Date created:		2011-09-29
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Image-Base-SVG
PORTVERSION=	4
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SVG image file output

BUILD_DEPENDS=	p5-Image-Base>=0:${PORTSDIR}/graphics/p5-Image-Base \
		p5-SVG>=2.38:${PORTSDIR}/textproc/p5-SVG \
		p5-SVG-Parser>=0:${PORTSDIR}/textproc/p5-SVG-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

MAN3=		Image::Base::SVG.3

post-patch:
	@${REINPLACE_CMD} -e 's|Image-Base-SVG|Image::Base::SVG|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
