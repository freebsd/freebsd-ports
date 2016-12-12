# Created by: Leif Pedersen <pedersen@meridian-enviro.com>
# $FreeBSD$

PORTNAME=	Shape
PORTVERSION=	0.04
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	http://users.tkk.fi/~jolma/pub/
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 module to read and write shapefiles via shapelib

LIB_DEPENDS=	libshp.so:devel/shapelib

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Shape/Shape.so

.include <bsd.port.mk>
