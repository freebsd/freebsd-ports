# Created by: erich@FreeBSD.org
# $FreeBSD$
#   $MCom: ports/graphics/gimp-app/Makefile,v 1.65 2012/12/30 18:09:11 mezz Exp $

PORTNAME?=	gimp-app
PORTVERSION=	2.8.10
PORTREVISION?=	6
PORTEPOCH?=	1
CATEGORIES?=	graphics gnome
MASTER_SITES=	ftp://ftp.gimp.org/pub/%SUBDIR%/ \
		http://gimp.mirrors.hoobly.com/%SUBDIR%/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/%SUBDIR%/ \
		ftp://ftp.is.co.za/mirror/ftp.gimp.org/gimp/%SUBDIR%/ \
		ftp://ftp.cc.uoc.gr/mirrors/gimp/%SUBDIR%/ \
		http://www.mirrorservice.org/sites/ftp.gimp.org/pub/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/%SUBDIR%,}
MASTER_SITE_SUBDIR=	gimp/v${PORTVERSION:R}
DISTNAME=	gimp-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNU Image Manipulation Program

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libgegl-0.2.so:${PORTSDIR}/graphics/gegl \
		libbabl-0.1.so:${PORTSDIR}/x11/babl
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

GNU_CONFIGURE=	yes
USES+=		desktop-file-utils gettext gmake libtool:keepla pathfix \
		pkgconfig tar:bzip2
USE_XORG=	xpm xmu xext
USE_GNOME+=	intltool intlhack gtk20 libartlgpl2 gnomehier
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc/gimp \
		--disable-gtk-doc \
		--without-linux-input \
		--with-print \
		--enable-default-binary \
		--with-lcms=lcms2 \
		--disable-gimp-console \
		--disable-python \
		--with-desktop-dir=${PREFIX}/share \
		--docdir=${PREFIX}/share/doc/gimp \
		--enable-default-binary
CONFIGURE_ENV=	GIMP_THREAD_LIBS=${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.if !defined(GIMP_SLAVE)

OPTIONS_DEFINE?=	AA DBUS LIBEXIF GHOSTSCRIPT GVFS HELPBROWSER JASPER \
			LIBMNG LIBRSVG2 POPPLER SIMD WMF
OPTIONS_DEFAULT=	AA DBUS LIBEXIF GVFS HELPBROWSER LIBMNG LIBRSVG2 \
			POPPLER WMF
AA_DESC=		Ascii-art Plug-in
HELPBROWSER_DESC=	Internal help browser

.endif

.include <bsd.port.options.mk>

.if defined(GIMP_SLAVE)
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
GIMP_LIBS=	`${PKG_CONFIG} --libs gimp-2.0`
GIMP_THUMB_LIBS=`${PKG_CONFIG} --libs gimpthumb-2.0`
GIMP_UI_LIBS=	`${PKG_CONFIG} --libs gimpui-2.0`

LIB_DEPENDS+=	libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app

.else

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MAA}
LIB_DEPENDS+=		libaa.so:${PORTSDIR}/graphics/aalib
PLIST_SUB+=		AA=""
.else
CONFIGURE_ARGS+=	--without-aa
PLIST_SUB+=		AA="@comment "
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=	--with-dbus
.else
CONFIGURE_ARGS+=	--without-dbus
.endif

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USE_GHOSTSCRIPT=	yes
CONFIGURE_ARGS+=	--with-gs
PLIST_SUB+=		GS=""
.else
CONFIGURE_ARGS+=	--without-gs
PLIST_SUB+=		GS="@comment "
.endif

.if ${PORT_OPTIONS:MGVFS}
USE_GNOME+=		gvfs
.else
LIB_DEPENDS+=		libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--without-gvfs
.endif

.if ${PORT_OPTIONS:MHELPBROWSER}
LIB_DEPENDS+=		libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
CONFIGURE_ARGS+=	--with-webkit
PLIST_SUB+=		HELPBROWSER=""
.else
CONFIGURE_ARGS+=	--without-webkit
PLIST_SUB+=		HELPBROWSER="@comment "
.endif

.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=		libjasper.so:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=	--with-libjasper
PLIST_SUB+=		JASPER=""
.else
CONFIGURE_ARGS+=		--without-libjasper
PLIST_SUB+=		JASPER="@comment "
.endif

.if ${PORT_OPTIONS:MLIBEXIF}
LIB_DEPENDS+=		libexif.so:${PORTSDIR}/graphics/libexif
PLIST_SUB+=		EXIF=""
.else
CONFIGURE_ARGS+=	--without-libexif
PLIST_SUB+=		EXIF="@comment "
.endif

.if ${PORT_OPTIONS:MLIBMNG}
LIB_DEPENDS+=		libmng.so:${PORTSDIR}/graphics/libmng
PLIST_SUB+=		MNG=""
.else
CONFIGURE_ARGS+=	--without-libmng
PLIST_SUB+=		MNG="@comment "
.endif

.if ${PORT_OPTIONS:MLIBRSVG2}
USE_GNOME+=		librsvg2
CONFIGURE_ARGS+=	--with-librsvg
PLIST_SUB+=		SVG=""
.else
CONFIGURE_ARGS+=	--without-librsvg
PLIST_SUB+=		SVG="@comment "
.endif

.if ${PORT_OPTIONS:MPOPPLER}
LIB_DEPENDS+=		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
PLIST_SUB+=		POPPLER=""
.else
CONFIGURE_ARGS+=	--without-poppler
PLIST_SUB+=		POPPLER="@comment "
.endif

.if !${PORT_OPTIONS:MSIMD}
CONFIGURE_ARGS+=	--disable-mmx \
			--disable-sse \
			--disable-altivec
.endif

.if ${PORT_OPTIONS:MWMF}
LIB_DEPENDS+=		libwmf.so:${PORTSDIR}/graphics/libwmf
PLIST_SUB+=		WMF=""
.else
CONFIGURE_ARGS+=	--without-wmf
PLIST_SUB+=		WMF="@comment "
.endif

.endif

.if ${OSVERSION} < 1000052
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif
LIBS+=-lexecinfo

post-patch:
	@${REINPLACE_CMD} -e 's|%%GIMP_LIBS%%|${GIMP_LIBS}|; \
		s|%%GIMP_THUMB_LIBS%%|${GIMP_THUMB_LIBS}|; \
		s|%%GIMP_UI_LIBS%%|${GIMP_UI_LIBS}|' \
			${WRKSRC}/plug-ins/pygimp/Makefile.in
	@${REINPLACE_CMD} -e 's/-u /-Wl,-u,/' \
		${WRKSRC}/app/Makefile.in
	@${REINPLACE_CMD} -e 's|"libpng"|"libpng15"|' \
	    	-e 's|x86_64|amd64|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
