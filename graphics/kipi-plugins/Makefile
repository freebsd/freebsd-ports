# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	kipi-plugins
PORTVERSION=	0.1.7
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF/kipi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	KDE Image Plugin Interface plugins

LIB_DEPENDS=	kipi.2:${PORTSDIR}/graphics/libkipi \
		kexiv2.5:${PORTSDIR}/graphics/libkexiv2 \
		png15:${PORTSDIR}/graphics/png \
		kdcraw.4:${PORTSDIR}/graphics/libkdcraw

OPTIONS_DEFINE=	ACQUIREIMAGES BATCHPROCESSIMAGES CALENDAR CDARCHIVING FINDIMAGES \
		FLICKREXPORT GALLERYEXPORT GPSSYNC HTMLEXPORT IMAGEVIEWER JPEGLOSSLESS \
		KAMERAKLIENT METADATAEDIT MPEGENCODER PICASAWEBEXPORT PRINTWIZARD RAWCONVERTER \
		SENDIMAGES SIMPLEVIEWEREXPORT SLIDESHOW TIMEADJUST WALLPAPER
ACQUIREIMAGES_DESC=	scanner/screenshot plugin
BATCHPROCESSIMAGES_DESC=	batch processing on images
CALENDAR_DESC=	create calendars
CDARCHIVING_DESC=	create album CDs
FINDIMAGES_DESC=	find duplicate images in albums
FLICKREXPORT_DESC=	export images to flickr account
GALLERYEXPORT_DESC=	export images to remote Gallery server
GPSSYNC_DESC=	geolocalize pictures
HTMLEXPORT_DESC=	export images collections into HTML page
IMAGEVIEWER_DESC=	OpenGL based image viewer
JPEGLOSSLESS_DESC=	batch processing without losing metainfo
KAMERAKLIENT_DESC=	GPhoto2 interface (import from cameras)
METADATAEDIT_DESC=	edit EXIF and IPTC pictures metadata
MPEGENCODER_DESC=	tool to build a video from images
PICASAWEBEXPORT_DESC=	export images to Picasa web service
PRINTWIZARD_DESC=	a print wizard
RAWCONVERTER_DESC=	convert RAW images from digital cameras
SENDIMAGES_DESC=	send images by email
SIMPLEVIEWEREXPORT_DESC=	export images to SimpleViewer
SLIDESHOW_DESC=	create a slideshow
TIMEADJUST_DESC=	adjust image file time and date
WALLPAPER_DESC=	set your image as wallpaper

OPTIONS_DEFAULT=	ACQUIREIMAGES BATCHPROCESSIMAGES CALENDAR CDARCHIVING FINDIMAGES \
		FLICKREXPORT GALLERYEXPORT GPSSYNC HTMLEXPORT IMAGEVIEWER JPEGLOSSLESS \
		KAMERAKLIENT METADATAEDIT MPEGENCODER PICASAWEBEXPORT PRINTWIZARD RAWCONVERTER \
		SENDIMAGES SIMPLEVIEWEREXPORT SLIDESHOW TIMEADJUST WALLPAPER

PORTSCOUT=	limit:^0\.1\.

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USES=		gettext
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-ipodexport

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MACQUIREIMAGES}
PLIST_SUB+=	ACQUIREIMAGES:=""
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
PLIST_SUB+=	ACQUIREIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-acquireimages
.endif

.if ${PORT_OPTIONS:MBATCHPROCESSIMAGES}
PLIST_SUB+=	BATCHPROCESSIMAGES:=""
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
PLIST_SUB+=	BATCHPROCESSIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-batchprocessimages
.endif

.if ${PORT_OPTIONS:MCALENDAR}
PLIST_SUB+=	CALENDAR:=""
LIB_DEPENDS+=	kcal.2:${PORTSDIR}/deskutils/kdepim3
.else
PLIST_SUB+=	CALENDAR:="@comment "
CONFIGURE_ARGS+=--disable-calendar
.endif

.if ${PORT_OPTIONS:MCDARCHIVING}
PLIST_SUB+=	CDARCHIVING:=""
RUN_DEPENDS+=	k3b:${PORTSDIR}/sysutils/k3b
.else
PLIST_SUB+=	CDARCHIVING:="@comment "
CONFIGURE_ARGS+=--disable-cdarchiving
.endif

.if ${PORT_OPTIONS:MFINDIMAGES}
PLIST_SUB+=	FINDIMAGES:=""
.else
PLIST_SUB+=	FINDIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-findimages
.endif

.if ${PORT_OPTIONS:MFLICKREXPORT}
PLIST_SUB+=	FLICKREXPORT:=""
.else
PLIST_SUB+=	FLICKREXPORT:="@comment "
CONFIGURE_ARGS+=--disable-flickrexport
.endif

.if ${PORT_OPTIONS:MGALLERYEXPORT}
PLIST_SUB+=	GALLERYEXPORT:=""
.else
PLIST_SUB+=	GALLERYEXPORT:="@comment "
CONFIGURE_ARGS+=--disable-galleryexport
.endif

.if ${PORT_OPTIONS:MGPSSYNC}
PLIST_SUB+=	GPSSYNC:=""
.else
PLIST_SUB+=	GPSSYNC:="@comment "
CONFIGURE_ARGS+=--disable-gpssync
.endif

.if ${PORT_OPTIONS:MHTMLEXPORT}
PLIST_SUB+=	HTMLEXPORT:=""
LIB_DEPENDS+=	xslt.2:${PORTSDIR}/textproc/libxslt
.else
PLIST_SUB+=	HTMLEXPORT:="@comment "
CONFIGURE_ARGS+=--disable-htmlexport
.endif

.if ${PORT_OPTIONS:MIMAGEVIEWER}
PLIST_SUB+=	IMAGEVIEWER:=""
.else
PLIST_SUB+=	IMAGEVIEWER:="@comment "
CONFIGURE_ARGS+=--disable-imageviewer
.endif

.if ${PORT_OPTIONS:MJPEGLOSSLESS}
PLIST_SUB+=	JPEGLOSSLESS:=""
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
PLIST_SUB+=	JPEGLOSSLESS:="@comment "
CONFIGURE_ARGS+=--disable-jpeglossless
.endif

.if ${PORT_OPTIONS:MKAMERAKLIENT}
PLIST_SUB+=	KAMERAKLIENT:=""
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
.else
PLIST_SUB+=	KAMERAKLIENT:="@comment "
CONFIGURE_ARGS+=--disable-kameraklient
.endif

.if ${PORT_OPTIONS:MMETADATAEDIT}
PLIST_SUB+=	METADATAEDIT:=""
.else
PLIST_SUB+=	METADATAEDIT:="@comment "
CONFIGURE_ARGS+=--disable-metadataedit
.endif

.if ${PORT_OPTIONS:MMPEGENCODER}
PLIST_SUB+=	MPEGENCODER:=""
RUN_DEPENDS+=	mpeg2enc:${PORTSDIR}/multimedia/mjpegtools \
		convert:${PORTSDIR}/graphics/ImageMagick
MAN1+=		images2mpg.1
.else
PLIST_SUB+=	MPEGENCODER:="@comment "
CONFIGURE_ARGS+=--disable-mpegencoder
.endif

.if ${PORT_OPTIONS:MPICASAWEBEXPORT}
PLIST_SUB+=	PICASAWEBEXPORT:=""
.else
PLIST_SUB+=	PICASAWEBEXPORT:="@comment "
CONFIGURE_ARGS+=--disable-picasawebexport
.endif

.if ${PORT_OPTIONS:MPRINTWIZARD}
PLIST_SUB+=	PRINTWIZARD:=""
.else
PLIST_SUB+=	PRINTWIZARD:="@comment "
CONFIGURE_ARGS+=--disable-printwizard
.endif

.if ${PORT_OPTIONS:MRAWCONVERTER}
PLIST_SUB+=	RAWCONVERTER:=""
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
PLIST_SUB+=	RAWCONVERTER:="@comment "
CONFIGURE_ARGS+=--disable-rawconverter
.endif

.if ${PORT_OPTIONS:MSENDIMAGES}
PLIST_SUB+=	SENDIMAGES:=""
.else
PLIST_SUB+=	SENDIMAGES:="@comment "
CONFIGURE_ARGS+=--disable-sendimages
.endif

.if ${PORT_OPTIONS:MSIMPLEVIEWEREXPORT}
PLIST_SUB+=	SIMPLEVIEWEREXPORT:=""
.else
PLIST_SUB+=	SIMPLEVIEWEREXPORT:="@comment "
CONFIGURE_ARGS+=--disable-simpleviewerexport
.endif

.if ${PORT_OPTIONS:MSLIDESHOW}
PLIST_SUB+=	SLIDESHOW:=""
.else
PLIST_SUB+=	SLIDESHOW:="@comment "
CONFIGURE_ARGS+=--disable-slideshow
.endif

.if ${PORT_OPTIONS:MTIMEADJUST}
PLIST_SUB+=	TIMEADJUST:=""
.else
PLIST_SUB+=	TIMEADJUST:="@comment "
CONFIGURE_ARGS+=--disable-timeadjust
.endif

.if ${PORT_OPTIONS:MWALLPAPER}
PLIST_SUB+=	WALLPAPER:=""
.else
PLIST_SUB+=	WALLPAPER:="@comment "
CONFIGURE_ARGS+=--disable-wallpaper
.endif

post-patch::
	@${REINPLACE_CMD} -e 's|-O2||g;s|-fno-schedule-insns -fno-inline||g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

.include <bsd.port.mk>
