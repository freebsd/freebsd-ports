# New ports collection makefile for:	digikam-plugins
# Date created: 			15 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	kipi-plugins
PORTVERSION=	0.1.3
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kipi

MAINTAINER=	ale@FreeBSD.org
COMMENT=	KDE Image Plugin Interface plugins

LIB_DEPENDS=	kipi.1:${PORTSDIR}/graphics/libkipi \
		exiv2.0:${PORTSDIR}/graphics/exiv2

OPTIONS=	ACQUIREIMAGES "scanner/screenshot plugin" on \
		BATCHPROCESSIMAGES "batch processing on images" on \
		CALENDAR "create calendars" on \
		CDARCHIVING "create album CDs" on \
		FINDIMAGES "find duplicate images in albums" on \
		FLICKREXPORT "export images to flickr account" on \
		GALLERYEXPORT "export images to remote Gallery server" on \
		GPSSYNC "geolocalize pictures" on \
		HTMLEXPORT "export images collections into HTML page" on \
		JPEGLOSSLESS "batch processing without losing metainfo" on \
		KAMERAKLIENT "GPhoto2 interface (import from cameras)" on \
		METADATAEDIT "edit EXIF and IPTC pictures metadata" on \
		MPEGENCODER "tool to build a video from images" on \
		PRINTWIZARD "a print wizard" on \
		RAWCONVERTER "convert RAW images from digital cameras" on \
		SENDIMAGES "send images by email" on \
		SIMPLEVIEWEREXPORT "export images to SimpleViewer" on \
		SLIDESHOW "create a slideshow" on \
		TIMEADJUST "adjust image file time and date" on \
		WALLPAPER "set your image as wallpaper" on

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=--enable-final
.endif

.if !defined(WITHOUT_ACQUIREIMAGES)
PLIST_SUB+=	ACQUIREIMAGES:=""
SUBDIRS+=	acquireimages
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
PLIST_SUB+=	ACQUIREIMAGES:="@comment "
.endif

.if !defined(WITHOUT_BATCHPROCESSIMAGES)
PLIST_SUB+=	BATCHPROCESSIMAGES:=""
SUBDIRS+=	batchprocessimages
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
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

.if !defined(WITHOUT_FLICKREXPORT)
PLIST_SUB+=	FLICKREXPORT:=""
SUBDIRS+=	flickrexport
.else
PLIST_SUB+=	FLICKREXPORT:="@comment "
.endif

.if !defined(WITHOUT_GALLERYEXPORT)
PLIST_SUB+=	GALLERYEXPORT:=""
SUBDIRS+=	galleryexport
.else
PLIST_SUB+=	GALLERYEXPORT:="@comment "
.endif

.if !defined(WITHOUT_GPSSYNC)
PLIST_SUB+=	GPSSYNC:=""
SUBDIRS+=	gpssync
.else
PLIST_SUB+=	GPSSYNC:="@comment "
.endif

.if !defined(WITHOUT_HTMLEXPORT)
PLIST_SUB+=	HTMLEXPORT:=""
SUBDIRS+=	htmlexport
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
.else
PLIST_SUB+=	HTMLEXPORT:="@comment "
.endif

.if !defined(WITHOUT_JPEGLOSSLESS)
PLIST_SUB+=	JPEGLOSSLESS:=""
SUBDIRS+=	jpeglossless
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
PLIST_SUB+=	JPEGLOSSLESS:="@comment "
.endif

.if !defined(WITHOUT_KAMERAKLIENT)
PLIST_SUB+=	KAMERAKLIENT:=""
SUBDIRS+=	kameraklient
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
.else
PLIST_SUB+=	KAMERAKLIENT:="@comment "
.endif

.if !defined(WITHOUT_METADATAEDIT)
PLIST_SUB+=	METADATAEDIT:=""
SUBDIRS+=	metadataedit
.else
PLIST_SUB+=	METADATAEDIT:="@comment "
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
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
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

.if !defined(WITHOUT_SIMPLEVIEWEREXPORT)
PLIST_SUB+=	SIMPLEVIEWEREXPORT:=""
SUBDIRS+=	simpleviewerexport
.else
PLIST_SUB+=	SIMPLEVIEWEREXPORT:="@comment "
.endif

.if !defined(WITHOUT_SLIDESHOW)
PLIST_SUB+=	SLIDESHOW:=""
SUBDIRS+=	slideshow
LIB_DEPENDS+=	Imlib2.4:${PORTSDIR}/graphics/imlib2
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
	@${REINPLACE_CMD} -e 's|-O2||g;s|-fno-schedule-insns -fno-inline||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's@%%SUBDIRS%%@${SUBDIRS}@g' ${WRKSRC}/kipi-plugins/Makefile.in
	@${REINPLACE_CMD} -e 's@\/usr\/bin\/k3b@${PREFIX}\/bin\/k3b@g' \
		${WRKSRC}/kipi-plugins/cdarchiving/cdarchiving.cpp \
		${WRKSRC}/kipi-plugins/cdarchiving/cdarchivingdialog.cpp

.include <bsd.port.post.mk>
