# New ports collection makefile for:    The GIMP
# Date created:         Mon Nov 18 21:28:43 CST 1996
# Whom:                 erich@FreeBSD.org
#
# $FreeBSD$
#   $MCom: ports/graphics/gimp-app/Makefile,v 1.53 2010/10/08 08:29:33 kwm Exp $
#

PORTNAME=	gimp-app
DISTVERSION=	2.6.11
PORTREVISION?=	1
PORTEPOCH?=	1
CATEGORIES?=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.fh-heilbronn.de/mirrors/ftp.gimp.org/%SUBDIR%/ \
		ftp://ftp.insync.net/pub/mirrors/ftp.gimp.org/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}
DISTNAME=	gimp-${DISTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNU Image Manipulation Program

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		lcms.1:${PORTSDIR}/graphics/lcms \
		gegl-0.1.105:${PORTSDIR}/graphics/gegl \
		babl-0.1:${PORTSDIR}/x11/babl
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

CONFLICTS=	gimp-app-devel-[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XORG=	xpm xmu xext
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME+=	gnomehack intltool intlhack gtk20 libartlgpl2 ltverhack \
		desktopfileutils
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc/gimp \
		--disable-gtk-doc \
		--without-print \
		--disable-python \
		--with-desktop-dir=${PREFIX}/share \
		--docdir=${PREFIX}/share/doc/gimp \
		--enable-default-binary \
		--without-gnomevfs
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GIMP_THREAD_LIBS=${PTHREAD_LIBS}

.if !defined(GIMP_SLAVE)
WANT_GNOME=	yes

OPTIONS?=	AA "Ascii Art plug-in" on \
		DBUS "D-BUS support" on \
		EXIF "reading meta-data from camera/scanner" on \
		GVFS "Use GVFS for the URI plug-in" on \
		HELPBROWSER "internal help browser" on \
		MNG "MNG format support" on \
		MP "multiple processor support" off \
		POPPLER "PDF format support" on \
		RSVG "SVG format support" on \
		SIMD "Use cpu-specific optimizations if available" off \
		WMF "wmf plugin" on
.endif

.include <bsd.port.pre.mk>

.if defined(GIMP_SLAVE)
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GIMP_LIBS=	`${PKG_CONFIG} --libs gimp-2.0`
GIMP_THUMB_LIBS=`${PKG_CONFIG} --libs gimpthumb-2.0`
GIMP_UI_LIBS=	`${PKG_CONFIG} --libs gimpui-2.0`

LIB_DEPENDS+=	gimp-2.0.0:${PORTSDIR}/graphics/gimp-app

.else

MAN1+=	gimp-2.6.1 gimptool-2.0.1
MAN5+=	gimprc-2.6.5
MLINKS=	gimp-2.6.1 gimp.1 \
	gimp-2.6.1 gimp-console-2.6.1 \
	gimp-console-2.6.1 gimp-console.1 \
	gimprc-2.6.5 gimprc.5

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${HAVE_GNOME:Mgnomehier}!="" || defined(WITH_GNOME)
USE_GNOME+=		desktopfileutils gnomehier
PLIST_SUB+=		GNOME=""
.else
PLIST_SUB+=		GNOME="@comment "
.endif

.if defined(WITH_AA)
LIB_DEPENDS+=		aa.1:${PORTSDIR}/graphics/aalib
PLIST_SUB+=		AA=""
.else
CONFIGURE_ARGS+=	--without-aa
PLIST_SUB+=		AA="@comment "
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=	--with-dbus
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if defined(WITH_EXIF)
LIB_DEPENDS+=		exif.12:${PORTSDIR}/graphics/libexif
.else
CONFIGURE_ARGS+=	--without-libexif
.endif

.if defined(WITH_GVFS) || ${HAVE_GNOME:Mgvfs}!=""
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/gnome-keyring
USE_GNOME+=	gvfs
.  if ${HAVE_GNOME:Mlibgnomeui}!=""
USE_GNOME+=	libgnomeui
.  endif
.endif

.if defined(WITH_HELPBROWSER)
LIB_DEPENDS+=		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2
CONFIGURE_ARGS+=	--with-webkit
PLIST_SUB+=		HELPBROWSER=""
.else
CONFIGURE_ARGS+=	--without-webkit
PLIST_SUB+=		HELPBROWSER="@comment "
.endif

.if defined(WITH_MNG)
LIB_DEPENDS+=		mng.1:${PORTSDIR}/graphics/libmng
PLIST_SUB+=		MNG=""
.else
CONFIGURE_ARGS+=	--without-libmng
PLIST_SUB+=		MNG="@comment "
.endif

.if defined(WITH_MP)
CONFIGURE_ARGS+=	--enable-mp
.else
CONFIGURE_ARGS+=	--disable-mp
.endif

.if defined(WITH_POPPLER)
LIB_DEPENDS+=		poppler-glib.5:${PORTSDIR}/graphics/poppler-gtk
PLIST_SUB+=		POPPLER=""
.else
CONFIGURE_ARGS+=	--without-poppler
PLIST_SUB+=		POPPLER="@comment "
.endif

.if defined(WITH_RSVG)
USE_GNOME+=		librsvg2
PLIST_SUB+=		SVG=""
.else
CONFIGURE_ARGS+=	--without-librsvg
PLIST_SUB+=		SVG="@comment "
.endif

.if defined(WITH_WMF)
LIB_DEPENDS+=		wmf.2:${PORTSDIR}/graphics/libwmf
PLIST_SUB+=		WMF=""
.else
CONFIGURE_ARGS+=	--without-wmf
PLIST_SUB+=		WMF="@comment "
.endif

.if !defined(WITH_SIMD)
CONFIGURE_ARGS+=	--disable-mmx \
			--disable-sse \
			--disable-altivec
.endif

.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%GIMP_LIBS%%|${GIMP_LIBS}|; \
		s|%%GIMP_THUMB_LIBS%%|${GIMP_THUMB_LIBS}|; \
		s|%%GIMP_UI_LIBS%%|${GIMP_UI_LIBS}|' \
			${WRKSRC}/plug-ins/pygimp/Makefile.in
	@${REINPLACE_CMD} -e 's|"libpng"|"libpng14"|' \
	    	-e 's|x86_64|amd64|g' \
		${WRKSRC}/configure

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
