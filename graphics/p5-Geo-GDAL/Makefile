# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-GDAL
PORTVERSION=	2.0.1
CATEGORIES=	graphics perl5
MASTER_SITES=	http://download.osgeo.org/gdal/${PORTVERSION}/ \
		ftp://ftp.remotesensing.org/pub/gdal/${PORTVERSION}/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	p5-
DISTNAME=	gdal-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl binding for GDAL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE.TXT

LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal

USE_PERL5=	build run
USES=		perl5 tar:xz

WRKSRC_SUBDIR=	swig/perl

post-patch:
	@${REINPLACE_CMD} -e 's| install| pure_install|' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|(const char \*)""|(char \*)""|' ${WRKSRC}/gdal_wrap.cpp ${WRKSRC}/ogr_wrap.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Geo/GDAL/Const/Const.so ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Geo/*/*.so

.include <bsd.port.mk>
