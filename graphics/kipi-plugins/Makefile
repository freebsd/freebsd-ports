# New ports collection makefile for:	digikam-plugins
# Date created: 			15 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikamplugins
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	digikam

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	Collection of plugins for Digikam

BUILD_DEPENDS=	imlib-config:${PORTSDIR}/graphics/imlib
LIB_DEPENDS=	digikam.0:${PORTSDIR}/graphics/digikam

OPTIONS=	ACQUIREIMAGES "scanner plugin" on \
		CDARCHIVING "plugin to create album CDs" on \
		COMMENTSEDITOR "plugin to edit image comments" on \
		IMAGESGALLERY "album to HTML gallery export" on \
		JPEGLOSSLESS "batch processing without losing meta info" on \
		MISCSOPERATIONS "Image2Desktop and Album2FileManager apps" on \
		MPEGENCODER "tool to build a video from images" on \
		PRINTWIZARD "a print wizard" on \
		RAWCONVERTER "convert RAW images from digital cameras" on \
		SENDIMAGES "an email images plugin" on \
		SLIDESHOW "create a slideshow" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--program-prefix=''
CONFIGURE_ENV+=	DO_NOT_COMPILE="${DO_NOT_COMPILE}"

.include <bsd.port.pre.mk>

.if defined(WITH_ACQUIREIMAGES)
PLIST_SUB+=	ACQUIREIMAGES:=""
.else
DO_NOT_COMPILE+=acquireimages
PLIST_SUB+=	ACQUIREIMAGES:="@comment "
.endif

.if defined(WITH_CDARCHIVING)
PLIST_SUB+=	CDARCHIVING:=""
RUN_DEPENDS+=	k3b:${PORTSDIR}/sysutils/k3b
.else
DO_NOT_COMPILE+=cdarchiving
PLIST_SUB+=	CDARCHIVING:="@comment "
.endif

.if defined(WITH_COMMENTSEDITOR)
PLIST_SUB+=	COMMENTSEDITOR:=""
.else
DO_NOT_COMPILE+=commentseditor
PLIST_SUB+=	COMMENTSEDITOR:="@comment "
.endif

.if defined(WITH_IMAGESGALLERY)
PLIST_SUB+=	IMAGESGALLERY:=""
.else
DO_NOT_COMPILE+=imagesgallery
PLIST_SUB+=	IMAGESGALLERY:="@comment "
.endif

.if defined(WITH_JPEGLOSSLESS)
PLIST_SUB+=	JPEGLOSSLESS:=""
.else
DO_NOT_COMPILE+=jpeglossless
PLIST_SUB+=	JPEGLOSSLESS:="@comment "
.endif

.if defined(WITH_MISCSOPERATIONS)
PLIST_SUB+=	MISCSOPERATIONS:=""
.else
DO_NOT_COMPILE+=miscsoperations
PLIST_SUB+=	MISCSOPERATIONS:="@comment "
.endif

.if defined(WITH_MPEGENCODER)
PLIST_SUB+=	MPEGENCODER:=""
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		convert:${PORTSDIR}/graphics/ImageMagick
.else
DO_NOT_COMPILE+=mpegencoder
PLIST_SUB+=	MPEGENCODER:="@comment "
.endif

.if defined(WITH_PRINTWIZARD)
PLIST_SUB+=	PRINTWIZARD:=""
.else
DO_NOT_COMPILE+=printwizard
PLIST_SUB+=	PRINTWIZARD:="@comment "
.endif

.if defined(WITH_RAWCONVERTER)
PLIST_SUB+=	RAWCONVERTER:=""
RUN_DEPENDS+=	dcraw:${PORTSDIR}/graphics/dcraw
.else
DO_NOT_COMPILE+=rawconverter
PLIST_SUB+=	RAWCONVERTER:="@comment "
.endif

.if defined(WITH_SENDIMAGES)
PLIST_SUB+=	SENDIMAGES:=""
.else
DO_NOT_COMPILE+=sendimages
PLIST_SUB+=	SENDIMAGES:="@comment "
.endif

.if defined(WITH_SLIDESHOW)
PLIST_SUB+=	SLIDESHOW:=""
.else
DO_NOT_COMPILE+=slideshow
PLIST_SUB+=	SLIDESHOW:="@comment "
.endif

pre-configure::
	${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
