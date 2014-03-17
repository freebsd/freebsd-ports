# Created by: slaven@rezic.de
# $FreeBSD$

PORTNAME=	merkaartor
PORTVERSION=	0.18.1
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://merkaartor.be/attachments/download/301/ \
		https://secure.ohos.nl/downloads/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	Openstreetmap mapping program

LICENSE=	GPLv2

LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libproj.so:${PORTSDIR}/graphics/proj

USES=		qmake tar:bzip2
USE_LDCONFIG=	yes

USE_QT4=	uic_build moc_build rcc_build \
		gui network svg webkit xml imageformats script scripttools

OPTIONS_DEFINE=	DEBUG GEOIMAGE NLS ZBAR
OPTIONS_DEFAULT=	GEOIMAGE

GEOIMAGE_DESC=	Enable geotagged images (needs exiv2)
GEOIMAGE_QMAKE_ON=	GEOIMAGE=1
GEOIMAGE_LIB_DEPENDS=	libexiv2.so:${PORTSDIR}/graphics/exiv2

ZBAR_DESC=	Read barcodes from walking papers (BROKEN)
ZBAR_QMAKE_ON=	ZBAR=1
ZBAR_LIB_DEPENDS=	libzbar.so:${PORTSDIR}/graphics/zbar

DEBUG_QMAKE_OFF=	NODEBUG=1 RELEASE=1

OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZBAR}
BROKEN=	Does not build with option ZBAR selected
.endif

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build

pre-build:
	@cd ${WRKSRC}/translations && ${LRELEASE} ../src/src.pro

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	@(cd ${WRKSRC}/translations && ${COPYTREE_SHARE} "merkaartor_*.qm" \
		${STAGEDIR}${DATADIR}/translations)
.endif

.include <bsd.port.mk>
