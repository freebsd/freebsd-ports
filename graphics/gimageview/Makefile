# Created by: TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
# $FreeBSD$

PORTNAME=	gimageview
PORTVERSION=	0.2.27
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF/gtkmmviewer/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another GTK+ based image viewer

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

OPTIONS_DEFINE=	SPLASH NLS LIBMNG LIBWMF LIBRSVG2 LIBEXIF MPLAYER LIBXINE IMLIB
OPTIONS_DEFAULT=SPLASH NLS LIBMNG LIBWMF LIBRSVG2 LIBEXIF MPLAYER
NO_OPTIONS_SORT=yes
SPLASH_DESC=	Show splash screen on startup
IMLIB_DESC=	imlib, disable gdk-pixbuf

USE_GNOME=	gtk20
USE_XORG=	xinerama ice
CONFIGURE_ARGS=	--with-gtk2
CFLAGS+=	-DUSE_GTK2

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MSPLASH)
CONFIGURE_ARGS+=	--disable-splash
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MIMLIB}
USE_GNOME+=	imlib
CONFIGURE_ARGS+=	--disable-gdk-pixbuf
.endif

.if ${PORT_OPTIONS:MLIBMNG}
LIB_DEPENDS+=	mng:${PORTSDIR}/graphics/libmng
PLIST_SUB+=	WITH_LIBMNG=""
.else
CONFIGURE_ARGS+=	--without-libmng
PLIST_SUB+=	WITH_LIBMNG="@comment "
.endif

.if ${PORT_OPTIONS:MLIBWMF}
LIB_DEPENDS+=	wmf:${PORTSDIR}/graphics/libwmf
PLIST_SUB+=	WITH_LIBWMF=""
.else
CONFIGURE_ARGS+=	--without-libwmf
PLIST_SUB+=	WITH_LIBWMF="@comment "
.endif

.if ${PORT_OPTIONS:MLIBRSVG2}
LIB_DEPENDS+=	rsvg-2:${PORTSDIR}/graphics/librsvg2
PLIST_SUB+=	WITH_LIBRSVG=""
.else
CONFIGURE_ARGS+=	--without-librsvg
PLIST_SUB+=	WITH_LIBRSVG="@comment "
.endif

.if ${PORT_OPTIONS:MLIBEXIF}
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-exit_view.c
.else
CONFIGURE_ARGS+=	--disable-exif
.endif

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
PLIST_SUB+=	WITH_LIBMPLAYER=""
.else
CONFIGURE_ARGS+=	--disable-mplayer
PLIST_SUB+=	WITH_LIBMPLAYER="@comment "
.endif

.if ${PORT_OPTIONS:MLIBXINE}
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--with-xine
PLIST_SUB+=	WITH_LIBXINE=""
.else
CONFIGURE_ARGS+=	--without-xine
PLIST_SUB+=	WITH_LIBXINE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/DATADIRNAME=lib/DATADIRNAME=share/g' \
		-e 's|echo aout|echo elf|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/gnome/apps/|/apps/|' \
		${WRKSRC}/gimageview.spec \
		${WRKSRC}/etc/Makefile.in

post-configure:
.if ${PORT_OPTIONS:MIMLIB}
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} -Ee \
		's/^(GDK_IMLIB_(CFLAGS|LIBS) =).*$$/$${1}/'
.endif

.include <bsd.port.post.mk>
