# New ports collection makefile for:   merkaartor
# Date created:        9 January 2009
# Whom:                slaven@rezic.de
#
# $FreeBSD$
#

PORTNAME=	merkaartor
PORTVERSION=	0.18.a
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	https://secure.ohos.nl/downloads/

MAINTAINER=	dev2@heesakkers.info
COMMENT=	An openstreetmap mapping program

LICENSE=	GPLv2

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		proj:${PORTSDIR}/graphics/proj

USE_BZIP2=	yes
USE_LDCONFIG=	yes

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build uic_build moc_build rcc_build \
		gui network svg webkit xml imageformats script scripttools
MAKE_JOBS_SAFE=	yes

.if exists(${LOCALBASE}/bin/gnome-session)
INSTALLS_ICONS=	yes
.endif

QMAKEFLAGS=	PREFIX=${PREFIX}

OPTIONS=	GEOIMAGE "Enable geotagged images (needs exiv2)" on\
		ZBAR     "Read barcodes from walking papers" off\
		DEBUG    "Enable debugging and verbose logging" off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GEOIMAGE)
QMAKEFLAGS+=	GEOIMAGE=1
LIB_DEPENDS+=	exiv2.10:${PORTSDIR}/graphics/exiv2
.endif

.if defined(WITH_ZBAR)
QMAKEFLAGS+=	ZBAR=1
LIB_DEPENDS+=	zbar:${PORTSDIR}/graphics/zbar
.endif

.if !defined(WITH_DEBUG)
QMAKEFLAGS+=	NODEBUG=1
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
QT_COMPONENTS+=	linguist_build

pre-build:
	@cd ${WRKSRC}/translations && lrelease-qt4 ../src/src.pro
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS}

.include <bsd.port.mk>
