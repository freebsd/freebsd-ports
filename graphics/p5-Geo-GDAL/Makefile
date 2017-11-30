# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Geo-GDAL
PORTVERSION=	2.2.3
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

BUILD_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny
LIB_DEPENDS=	libgdal.so:graphics/gdal

USES=		perl5 tar:xz

WRKSRC_SUBDIR=	swig/perl

post-patch:
	@${LN} -s ${LOCALBASE}/bin/gdal-config ${WRKSRC}/../../apps/gdal-config
	@${REINPLACE_CMD} -e 's| INSTALL_BASE=.*||; s| install| pure_install|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|(const char \*)""|(char \*)""|' ${WRKSRC}/gdal_wrap.cpp ${WRKSRC}/ogr_wrap.cpp

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Geo/GDAL/Const/Const.so ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Geo/*/*.so

.include <bsd.port.mk>
