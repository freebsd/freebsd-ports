# Created by: Slaven Rezic <slaven@rezic.de>
# $FreeBSD$

PORTNAME=	merkaartor
PORTVERSION=	0.18.2
PORTREVISION=	8
CATEGORIES=	astro

MAINTAINER=	dev2@heesakkers.info
COMMENT=	Openstreetmap mapping program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libquazip5.so:archivers/quazip@qt5

USE_GITHUB=	yes
GH_ACCOUNT=	openstreetmap
USES=		pkgconfig sqlite:3 qmake
USE_LDCONFIG=	yes

QMAKE_ARGS=	SYSTEM_QUAZIP=1
USE_QT5=	buildtools_build \
		concurrent core gui imageformats network printsupport svg \
		webkit widgets xml

OPTIONS_DEFINE=	DEBUG GEOIMAGE NLS PROTOBUF ZBAR
OPTIONS_DEFAULT=	GEOIMAGE

GEOIMAGE_DESC=	Enable geotagged images (needs exiv2)
GEOIMAGE_QMAKE_ON=	GEOIMAGE=1
GEOIMAGE_LIB_DEPENDS=	libexiv2.so:graphics/exiv2

PROTOBUF_DESC=	Protobuf Binary Format support
PROTOBUF_QMAKE_ON=	PROTOBUF=1
PROTOBUF_LIB_DEPENDS=	libprotobuf.so:devel/protobuf

ZBAR_DESC=	Read barcodes from walking papers (BROKEN)
ZBAR_QMAKE_ON=	ZBAR=1
ZBAR_LIB_DEPENDS=	libzbar.so:graphics/zbar
# graphics/zbar needs to be built with Qt support (and needs a Qt5 version)
ZBAR_BROKEN=	Does not build with option ZBAR selected

DEBUG_QMAKE_OFF=	NODEBUG=1 RELEASE=1

NLS_USE=	QT5=linguisttools_build

INSTALLS_ICONS= yes

OPTIONS_SUB=	yes

pre-build-NLS-on:
	@cd ${WRKSRC}/translations && ${LRELEASE} ../src/src.pro

pre-build-PROTOBUF-on:
	@cd ${WRKSRC}/src/ImportExport && ${LOCALBASE}/bin/protoc --cpp_out=. \
		fileformat.proto osmformat.proto

post-install-NLS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/translations
	@(cd ${WRKSRC}/translations && ${COPYTREE_SHARE} "merkaartor_*.qm" \
		${STAGEDIR}${DATADIR}/translations)

.include <bsd.port.mk>
