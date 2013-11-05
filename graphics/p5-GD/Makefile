# $FreeBSD$

PORTNAME=	GD
PORTVERSION=	2.50
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to Gd Graphics Library version2

LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	-options "JPEG,FT,XPM,GIF,PNG" \
		-lib_gd_path ${LOCALBASE} -lib_ft_path} \
		-lib_png_path ${LOCALBASE} -lib_zlib_path

.include <bsd.port.mk>
