# Created by: Anes Mukhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	Image-LibExif
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anes@anes.su
COMMENT=	Read EXIF module

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	libexif>=0.6.18:graphics/libexif
LIB_DEPENDS=	libexif.so:graphics/libexif
RUN_DEPENDS=	libexif>=0.6.18:graphics/libexif

USE_PERL5=	configure
USES=		perl5 pkgconfig

.include <bsd.port.mk>
