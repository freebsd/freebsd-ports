# New ports collection makefile for:   merkaartor
# Date created:        9 January 2009
# Whom:                slaven@rezic.de
#
# $FreeBSD$
#

PORTNAME=	merkaartor
PORTVERSION=	0.18.1
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://merkaartor.be/attachments/download/301/ \
		https://secure.ohos.nl/downloads/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	An openstreetmap mapping program

LICENSE=	GPLv2

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		proj:${PORTSDIR}/graphics/proj

USE_BZIP2=	yes
USE_LDCONFIG=	yes

USE_QT4=	qmake_build uic_build moc_build rcc_build \
		gui network svg webkit xml imageformats script scripttools
MAKE_JOBS_SAFE=	yes

.if exists(${LOCALBASE}/bin/gnome-session)
INSTALLS_ICONS=	yes
.endif

QMAKEFLAGS=	PREFIX=${PREFIX}

OPTIONS_DEFINE=	GEOIMAGE ZBAR DEBUG
GEOIMAGE_DESC=	Enable geotagged images (needs exiv2)
ZBAR_DESC=	Read barcodes from walking papers
OPTIONS_DEFAULT=	GEOIMAGE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEOIMAGE}
QMAKEFLAGS+=	GEOIMAGE=1
LIB_DEPENDS+=	exiv2:${PORTSDIR}/graphics/exiv2
.endif

.if ${PORT_OPTIONS:MZBAR}
QMAKEFLAGS+=	ZBAR=1
LIB_DEPENDS+=	zbar:${PORTSDIR}/graphics/zbar
.endif

.if empty(PORT_OPTIONS:MDEBUG)
QMAKEFLAGS+=	NODEBUG=1 RELEASE=1
.endif

.if empty(PORT_OPTIONS:MNLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
USE_QT4+=	linguist_build

pre-build:
	@cd ${WRKSRC}/translations && lrelease-qt4 ../src/src.pro
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

.include <bsd.port.mk>
