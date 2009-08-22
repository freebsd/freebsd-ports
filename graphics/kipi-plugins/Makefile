# New ports collection makefile for:	digikam-plugins
# Date created: 			15 February 2004
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	kipi-plugins
PORTVERSION=	0.1.7
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF/kipi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	KDE Image Plugin Interface plugins

LIB_DEPENDS=	kipi.2:${PORTSDIR}/graphics/libkipi \
		kexiv2.5:${PORTSDIR}/graphics/libkexiv2 \
		kdcraw.4:${PORTSDIR}/graphics/libkdcraw

OPTIONS=	ACQUIREIMAGES "scanner/screenshot plugin" on \
		BATCHPROCESSIMAGES "batch processing on images" on \
		CALENDAR "create calendars" on \
		CDARCHIVING "create album CDs" on \
		FINDIMAGES "find duplicate images in albums" on \
		FLICKREXPORT "export images to flickr account" on \
		GALLERYEXPORT "export images to remote Gallery server" on \
		GPSSYNC "geolocalize pictures" on \
		HTMLEXPORT "export images collections into HTML page" on \
		IMAGEVIEWER "OpenGL based image viewer" on \
		JPEGLOSSLESS "batch processing without losing metainfo" on \
		KAMERAKLIENT "GPhoto2 interface (import from cameras)" on \
		METADATAEDIT "edit EXIF and IPTC pictures metadata" on \
		MPEGENCODER "tool to build a video from images" on \
		PICASAWEBEXPORT "export images to Picasa web service" on \
		PRINTWIZARD "a print wizard" on \
		RAWCONVERTER "convert RAW images from digital cameras" on \
		SENDIMAGES "send images by email" on \
		SIMPLEVIEWEREXPORT "export images to SimpleViewer" on \
		SLIDESHOW "create a slideshow" on \
		TIMEADJUST "adjust image file time and date" on \
		WALLPAPER "set your image as wallpaper" on

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-ipodexport

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ACQUIREIMAGES)
PLIST_SUB+=	ACQUIREIMAGES:=""
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
PLIST_SUB+=	ACQUIREIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-acquireimages
.endif

.if !defined(WITHOUT_BATCHPROCESSIMAGES)
PLIST_SUB+=	BATCHPROCESSIMAGES:=""
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
PLIST_SUB+=	BATCHPROCESSIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-batchprocessimages
.endif

.if !defined(WITHOUT_CALENDAR)
PLIST_SUB+=	CALENDAR:=""
LIB_DEPENDS+=	kcal.2:${PORTSDIR}/deskutils/kdepim3
.else
PLIST_SUB+=	CALENDAR:="@comment "
CONFIGURE_ARGS+=--disable-calendar
.endif

.if !defined(WITHOUT_CDARCHIVING)
PLIST_SUB+=	CDARCHIVING:=""
RUN_DEPENDS+=	k3b:${PORTSDIR}/sysutils/k3b
.else
PLIST_SUB+=	CDARCHIVING:="@comment "
CONFIGURE_ARGS+=--disable-cdarchiving
.endif

.if !defined(WITHOUT_FINDIMAGES)
PLIST_SUB+=	FINDIMAGES:=""
.else
PLIST_SUB+=	FINDIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-findimages
.endif

.if !defined(WITHOUT_FLICKREXPORT)
PLIST_SUB+=	FLICKREXPORT:=""
.else
PLIST_SUB+=	FLICKREXPORT:="@comment "
CONFIGURE_ARGS+=--disable-flickrexport
.endif

.if !defined(WITHOUT_GALLERYEXPORT)
PLIST_SUB+=	GALLERYEXPORT:=""
.else
PLIST_SUB+=	GALLERYEXPORT:="@comment "
CONFIGURE_ARGS+=--disable-galleryexport
.endif

.if !defined(WITHOUT_GPSSYNC)
PLIST_SUB+=	GPSSYNC:=""
.else
PLIST_SUB+=	GPSSYNC:="@comment "
CONFIGURE_ARGS+=--disable-gpssync
.endif

.if !defined(WITHOUT_HTMLEXPORT)
PLIST_SUB+=	HTMLEXPORT:=""
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
.else
PLIST_SUB+=	HTMLEXPORT:="@comment "
CONFIGURE_ARGS+=--disable-htmlexport
.endif

.if !defined(WITHOUT_IMAGEVIEWER)
PLIST_SUB+=	IMAGEVIEWER:=""
.else
PLIST_SUB+=	IMAGEVIEWER:="@comment "
CONFIGURE_ARGS+=--disable-imageviewer
.endif

.if !defined(WITHOUT_JPEGLOSSLESS)
PLIST_SUB+=	JPEGLOSSLESS:=""
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
PLIST_SUB+=	JPEGLOSSLESS:="@comment "
CONFIGURE_ARGS+=--disable-jpeglossless
.endif

.if !defined(WITHOUT_KAMERAKLIENT)
PLIST_SUB+=	KAMERAKLIENT:=""
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
.else
PLIST_SUB+=	KAMERAKLIENT:="@comment "
CONFIGURE_ARGS+=--disable-kameraklient
.endif

.if !defined(WITHOUT_METADATAEDIT)
PLIST_SUB+=	METADATAEDIT:=""
.else
PLIST_SUB+=	METADATAEDIT:="@comment "
CONFIGURE_ARGS+=--disable-metadataedit
.endif

.if !defined(WITHOUT_MPEGENCODER)
PLIST_SUB+=	MPEGENCODER:=""
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		convert:${PORTSDIR}/graphics/ImageMagick
MAN1+=		images2mpg.1
.else
PLIST_SUB+=	MPEGENCODER:="@comment "
CONFIGURE_ARGS+=--disable-mpegencoder
.endif

.if !defined(WITHOUT_PICASAWEBEXPORT)
PLIST_SUB+=	PICASAWEBEXPORT:=""
.else
PLIST_SUB+=	PICASAWEBEXPORT:="@comment "
CONFIGURE_ARGS+=--disable-picasawebexport
.endif

.if !defined(WITHOUT_PRINTWIZARD)
PLIST_SUB+=	PRINTWIZARD:=""
.else
PLIST_SUB+=	PRINTWIZARD:="@comment "
CONFIGURE_ARGS+=--disable-printwizard
.endif

.if !defined(WITHOUT_RAWCONVERTER)
PLIST_SUB+=	RAWCONVERTER:=""
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
PLIST_SUB+=	RAWCONVERTER:="@comment "
CONFIGURE_ARGS+=--disable-rawconverter
.endif

.if !defined(WITHOUT_SENDIMAGES)
PLIST_SUB+=	SENDIMAGES:=""
.else
PLIST_SUB+=	SENDIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-sendimages
.endif

.if !defined(WITHOUT_SIMPLEVIEWEREXPORT)
PLIST_SUB+=	SIMPLEVIEWEREXPORT:=""
.else
PLIST_SUB+=	SIMPLEVIEWEREXPORT:="@comment "
CONFIGURE_ARGS+=--disable-simpleviewerexport
.endif

.if !defined(WITHOUT_SLIDESHOW)
PLIST_SUB+=	SLIDESHOW:=""
.else
PLIST_SUB+=	SLIDESHOW:="@comment "
CONFIGURE_ARGS+=--disable-slideshow
.endif

.if !defined(WITHOUT_TIMEADJUST)
PLIST_SUB+=	TIMEADJUST:=""
.else
PLIST_SUB+=	TIMEADJUST:="@comment "
CONFIGURE_ARGS+=--disable-timeadjust
.endif

.if !defined(WITHOUT_WALLPAPER)
PLIST_SUB+=	WALLPAPER:=""
.else
PLIST_SUB+=	WALLPAPER:="@comment "
CONFIGURE_ARGS+=--disable-wallpaper
.endif

post-patch::
	@${REINPLACE_CMD} -e 's|-O2||g;s|-fno-schedule-insns -fno-inline||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
