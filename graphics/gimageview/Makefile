# New ports collection makefile for:	gimageview
# Date Created:				5 Feb 2002
# Whom:		TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gimageview
PORTVERSION=	0.2.27
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/gtkmmviewer/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Yet another GTK+ based image viewer

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_GMAKE=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

OPTIONS=	SPLASH "Show splash on startup" on \
		NLS "Build with gettext support" on \
		LIBMNG "Build with libmng support" on \
		LIBWMF "Build with libwmf support" on \
		LIBRSVG "Build with librsvg support" off \
		LIBRSVG2 "Build with librsvg-2 support" on \
		LIBEXIF "Build with libexif support" on \
		MPLAYER "Build with Mplayer support" on \
		LIBXINE "Build with Xine support" off

USE_GNOME=	gtk20
USE_XORG=	xinerama ice
CONFIGURE_ARGS=	--with-gtk2
CFLAGS+=	-DUSE_GTK2

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SPLASH)
CONFIGURE_ARGS+=	--disable-splash
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME+=	imlib
PKGNAMESUFFIX=	-imlib
WITH_IMLIB=	yes
CONFIGURE_ARGS+=	--disable-gdk-pixbuf
.endif

.if !defined(WITHOUT_LIBMNG)
LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng
PLIST_SUB+=	WITH_LIBMNG=""
.else
CONFIGURE_ARGS+=	--without-libmng
PLIST_SUB+=	WITH_LIBMNG="@comment "
.endif

.if !defined(WITHOUT_LIBWMF)
LIB_DEPENDS+=	wmf.2:${PORTSDIR}/graphics/libwmf
PLIST_SUB+=	WITH_LIBWMF=""
.else
CONFIGURE_ARGS+=	--without-libwmf
PLIST_SUB+=	WITH_LIBWMF="@comment "
.endif

.if defined(WITH_LIBRSVG)
LIB_DEPENDS+=	rsvg.1:${PORTSDIR}/graphics/librsvg
.endif

.if !defined(WITHOUT_LIBRSVG2) && !defined(WITH_LIBRSVG)
LIB_DEPENDS+=	rsvg-2.2:${PORTSDIR}/graphics/librsvg2
.endif

.if defined(WITH_LIBRSVG) || !defined(WITHOUT_LIBRSVG2)
PLIST_SUB+=	WITH_LIBRSVG=""
.else
CONFIGURE_ARGS+=	--without-librsvg
PLIST_SUB+=	WITH_LIBRSVG="@comment "
.endif

.if !defined(WITHOUT_LIBEXIF)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-exit_view.c
.else
CONFIGURE_ARGS+=	--disable-exif
.endif

.if !defined(WITHOUT_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
PLIST_SUB+=	WITH_LIBMPLAYER=""
.else
CONFIGURE_ARGS+=	--disable-mplayer
PLIST_SUB+=	WITH_LIBMPLAYER="@comment "
.endif

.if defined(WITH_LIBXINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
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
.if !defined(WITH_IMLIB)
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} -Ee \
		's/^(GDK_IMLIB_(CFLAGS|LIBS) =).*$$/$${1}/'
.endif

.include <bsd.port.post.mk>
