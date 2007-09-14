# New ports collection makefile for:	p5-Image-Math-Constrain
# Date created:		8 September 2007
# Whom:			coryking
#
# $FreeBSD$
#

PORTNAME=	Image-Math-Constrain
PORTVERSION=	1.01
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Image
PKGNAMEPREFIX=	p5-

MAINTAINER=	coryking@mozimedia.com
COMMENT=	Scaling math used in image size constraining (such as thumbnails)

BUILD_DEPENDS=	p5-PathTools>=3.25:${PORTSDIR}/devel/p5-PathTools
RUN_DEPENDS=	p5-PathTools>=3.25:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=		Image::Math::Constrain.3

.include <bsd.port.mk>
