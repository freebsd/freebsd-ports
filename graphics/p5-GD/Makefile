# $FreeBSD$

PORTNAME=	GD
PORTVERSION=	2.53
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to Gd Graphics Library version2

LICENSE=	ART10 GPLv1 GPLv2 GPLv3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

CONFIGURE_ENV=	options="FT,GIF,JPEG,PNG,XPM" \
		lib_ft_path=${LOCALBASE} \
		lib_gd_path=${LOCALBASE} \
		lib_jpeg_path=${LOCALBASE} \
		lib_png_path=${LOCALBASE} \
		lib_zlib_path=/usr
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
