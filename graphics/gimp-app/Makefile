# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gimp
PORTVERSION=	2.2.4
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNU Image Manipulation Program

CONFLICTS=	gimp-1.*

SHLIBVER?=	200

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack intltool intlhack gtk20 libartlgpl2
WANT_GNOME=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PLIST_SUB=	SHLIBVER="${SHLIBVER}"
CONFIGURE_ARGS=	--disable-perl \
		--with-html-dir=${DOCSDIR} \
		--disable-gtk-doc \
		--enable-static
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GIMP_DISTFILE=	${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAN1=	gimp.1 gimp-2.2.1 gimp-remote.1 gimp-remote-2.2.1 gimptool-2.0.1
MAN5=	gimprc.5 gimprc-2.2.5

.if defined(WITHOUT_WMF) && !exists(${LOCALBASE}/bin/libwmf-config)
PLIST_SUB+=		WMF="@comment "
.else
LIB_DEPENDS+=		wmf.2:${PORTSDIR}/graphics/libwmf
PLIST_SUB+=		WMF=""
.endif

.if defined(WITHOUT_RSVG2) && !exists(${X11BASE}/bin/rsvg)
PLIST_SUB+=		SVG="@comment "
.else
USE_GNOME+=		librsvg2
PLIST_SUB+=		SVG=""
.endif

.if defined(WITHOUT_AA)
CONFIGURE_ARGS+=	--without-aa
PLIST_SUB+=		AA="@comment "
.else
LIB_DEPENDS+=		aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=		AA=""
.endif

.if defined(WITHOUT_EXIF)
CONFIGURE_ARGS+=	--without-libexif
.else
LIB_DEPENDS+=		exif.12:${PORTSDIR}/graphics/libexif
.endif

.if defined(WITHOUT_MNG)
CONFIGURE_ARGS+=	--without-libmng
PLIST_SUB+=		MNG="@comment "
.else
LIB_DEPENDS+=		mng.1:${PORTSDIR}/graphics/libmng
PLIST_SUB+=		MNG=""
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ARGS+=	--without-libpng
PLIST_SUB+=		PNG="@comment "
.else
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=		PNG=""
.endif

.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=	--without-libjpeg
PLIST_SUB+=		JPEG="@comment "
.else
LIB_DEPENDS+=		jpeg.9:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=		JPEG=""
.endif

.if defined(WITHOUT_TIFF)
CONFIGURE_ARGS+=	--without-libtiff
PLIST_SUB+=		TIFF="@comment "
.else
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=		TIFF=""
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=		yes
USE_GNOME+=		pygtk2
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		PYTHON:=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		PYTHON:="@comment "
.endif

.if defined(WITHOUT_PRINT)
CONFIGURE_ARGS+=	--disable-print
PLIST_SUB+=		PRINT="@comment "
.else
LIB_DEPENDS+=		gimpprint.2:${PORTSDIR}/print/gimp-print
PLIST_SUB+=		PRINT=""
.endif

.if defined(WITH_MP)
CONFIGURE_ARGS+=	--enable-mp
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgnomepanel}!=""
USE_GNOME+=		gnomepanel desktopfileutils
CONFIGURE_ARGS+=	--with-desktop-dir=${X11BASE}/share/gnome
CONFIGURE_ENV+=		GIMP_THREAD_LIBS=${PTHREAD_LIBS}
PKGNAMESUFFIX=		-gnome
PLIST_SUB+=		GNOMEPANEL:=""
GNOME_ENABLED=		yes
.else
PLIST_SUB+=		GNOMEPANEL:="@comment "
CONFIGURE_ENV+=		GIMP_THREAD_LIBS=${PTHREAD_LIBS}
.endif

.if ${HAVE_GNOME:Mlibgtkhtml}!="" || defined(WITH_HTML_HELP_BROWSER)
USE_GNOME+=		libgtkhtml
PLIST_SUB+=		HELPBROWSER:=""
.else
PLIST_SUB+=		HELPBROWSER:="@comment "
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "gimp has the following tunable option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	WITH_DEBUG=yes		Turns on debugging"
	@${ECHO_MSG} "	WITH_PYTHON=yes		Turns on Python-Fu support"
	@${ECHO_MSG} "	WITHOUT_PRINT=yes	Turns off GIMP printing"
	@${ECHO_MSG} "	WITH_HTML_HELP_BROWSER=yes	Turns on the GIMP help browser"
	@${ECHO_MSG} "	WITH_MP=yes 		Turns on multiple-processor support"
	@${ECHO_MSG} "	WITHOUT_WMF=yes		Turns off wmf support"
	@${ECHO_MSG} "	WITHOUT_RSVG2=yes	Turns off rsvg2 support"
	@${ECHO_MSG} "	WITHOUT_AA=yes		Turns off aa support"
	@${ECHO_MSG} "	WITHOUT_EXIF=yes	Turns off exif support"
	@${ECHO_MSG} "	WITHOUT_MNG=yes		Turns off mng support"
	@${ECHO_MSG} "	WITHOUT_PNG=yes		Turns off png support"
	@${ECHO_MSG} "	WITHOUT_JPEG=yes	Turns off jpeg support"
	@${ECHO_MSG} "	WITHOUT_TIFF=yes	Turns off tiff support"
	@${ECHO_MSG} ""

.if defined(GNOME_ENABLED)
post-install:
	@-update-desktop-database
.endif

.include <bsd.port.post.mk>
