# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Image-Base-SVG
PORTVERSION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SVG image file output

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Image-Base>=0:graphics/p5-Image-Base \
		p5-SVG>=2.38:textproc/p5-SVG \
		p5-SVG-Parser>=0:textproc/p5-SVG-Parser

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
