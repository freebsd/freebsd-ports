# New ports collection makefile for:	digikam-plugins
# Date created: 			15 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	kipi-plugins
PORTVERSION=	0.1.0.b.2
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	digikam
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b./-beta/}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	KDE Image Plugin Interface plugins

LIB_DEPENDS=	kexif.1:${PORTSDIR}/graphics/libkexif \
		kipi.0:${PORTSDIR}/graphics/libkipi \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2 \
		Imlib2.3:${PORTSDIR}/graphics/imlib2

OPTIONS=	ACQUIREIMAGES "scanner/screenshot plugin" on \
		BATCHPROCESSIMAGES "batch processing on images" on \
		CALENDAR "create calendars" on \
		CDARCHIVING "create album CDs" on \
		FINDIMAGES "find duplicate images in albums" on \
		GALLERYEXPORT "album to remote Gallery server export" on \
		IMAGESGALLERY "album to HTML gallery export" on \
		JPEGLOSSLESS "batch processing without losing meta info" on \
		MPEGENCODER "tool to build a video from images" on \
		PRINTWIZARD "a print wizard" on \
		RAWCONVERTER "convert RAW images from digital cameras" on \
		SENDIMAGES "an email images plugin" on \
		SLIDESHOW "create a slideshow" on \
		TIMEADJUST "adjust image file time and date" on \
		WALLPAPER "set your image as wallpaper" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes
CONFIGURE_ARGS+=--program-prefix=''

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=--enable-final
.endif

.if !defined(WITHOUT_ACQUIREIMAGES)
PLIST_SUB+=	ACQUIREIMAGES:=""
SUBDIRS+=	acquireimages
.else
PLIST_SUB+=	ACQUIREIMAGES:="@comment "
.endif

.if !defined(WITHOUT_BATCHPROCESSIMAGES)
PLIST_SUB+=	BATCHPROCESSIMAGES:=""
SUBDIRS+=	batchprocessimages
.else
PLIST_SUB+=	BATCHPROCESSIMAGES:="@comment "
.endif

.if !defined(WITHOUT_CALENDAR)
PLIST_SUB+=	CALENDAR:=""
SUBDIRS+=	calendar
.else
PLIST_SUB+=	CALENDAR:="@comment "
.endif

.if !defined(WITHOUT_CDARCHIVING)
PLIST_SUB+=	CDARCHIVING:=""
RUN_DEPENDS+=	k3b:${PORTSDIR}/sysutils/k3b
SUBDIRS+=	cdarchiving
.else
PLIST_SUB+=	CDARCHIVING:="@comment "
.endif

.if !defined(WITHOUT_FINDIMAGES)
PLIST_SUB+=	FINDIMAGES:=""
SUBDIRS+=	findimages
.else
PLIST_SUB+=	FINDIMAGES:="@comment "
.endif

.if !defined(WITHOUT_GALLERYEXPORT)
PLIST_SUB+=	GALLERYEXPORT:=""
SUBDIRS+=	galleryexport
.else
PLIST_SUB+=	GALLERYEXPORT:="@comment "
.endif

.if !defined(WITHOUT_IMAGESGALLERY)
PLIST_SUB+=	IMAGESGALLERY:=""
SUBDIRS+=	imagesgallery
.else
PLIST_SUB+=	IMAGESGALLERY:="@comment "
.endif

.if !defined(WITHOUT_JPEGLOSSLESS)
PLIST_SUB+=	JPEGLOSSLESS:=""
SUBDIRS+=	jpeglossless
.else
PLIST_SUB+=	JPEGLOSSLESS:="@comment "
.endif

.if !defined(WITHOUT_MPEGENCODER)
PLIST_SUB+=	MPEGENCODER:=""
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		convert:${PORTSDIR}/graphics/ImageMagick
MAN1+=		images2mpg.1
SUBDIRS+=	mpegencoder
.else
PLIST_SUB+=	MPEGENCODER:="@comment "
.endif

.if !defined(WITHOUT_PRINTWIZARD)
PLIST_SUB+=	PRINTWIZARD:=""
SUBDIRS+=	printwizard
.else
PLIST_SUB+=	PRINTWIZARD:="@comment "
.endif

.if !defined(WITHOUT_RAWCONVERTER)
PLIST_SUB+=	RAWCONVERTER:=""
RUN_DEPENDS+=	dcraw:${PORTSDIR}/graphics/dcraw
MAN1+=		kipidcrawclient.1
SUBDIRS+=	rawconverter
.else
PLIST_SUB+=	RAWCONVERTER:="@comment "
.endif

.if !defined(WITHOUT_SENDIMAGES)
PLIST_SUB+=	SENDIMAGES:=""
SUBDIRS+=	sendimages
.else
PLIST_SUB+=	SENDIMAGES:="@comment "
.endif

.if !defined(WITHOUT_SLIDESHOW)
PLIST_SUB+=	SLIDESHOW:=""
SUBDIRS+=	slideshow
.else
PLIST_SUB+=	SLIDESHOW:="@comment "
.endif

.if !defined(WITHOUT_TIMEADJUST)
PLIST_SUB+=	TIMEADJUST:=""
SUBDIRS+=	timeadjust
.else
PLIST_SUB+=	TIMEADJUST:="@comment "
.endif

.if !defined(WITHOUT_WALLPAPER)
PLIST_SUB+=	WALLPAPER:=""
SUBDIRS+=	wallpaper
.else
PLIST_SUB+=	WALLPAPER:="@comment "
.endif

post-patch::
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's@%%SUBDIRS%%@${SUBDIRS}@g' ${WRKSRC}/kipi-plugins/Makefile.in
	@${REINPLACE_CMD} -e 's@\/usr\/bin\/k3b@${PREFIX}\/bin\/k3b@g' \
		${WRKSRC}/kipi-plugins/cdarchiving/cdarchiving.cpp \
		${WRKSRC}/kipi-plugins/cdarchiving/cdarchivingdialog.cpp

.include <bsd.port.post.mk>
