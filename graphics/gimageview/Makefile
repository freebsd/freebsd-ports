# New ports collection makefile for:	gimageview
# Date Created:				5 Feb 2002
# Whom:		TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gimageview
PORTVERSION=	0.2.27
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmmviewer

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Yet another GTK+ based image viewer

USE_GMAKE=	yes
USE_GETTEXT=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

OPTIONS=	SPLASH "Show splash on startup" On

.if defined(WITH_GTK2)
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-gtk2
CFLAGS+=	-DUSE_GTK2
.else
USE_GNOME=	gdkpixbuf gnomehier
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SPLASH)
CONFIGURE_ARGS+=	--disable-splash
.endif

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME+=	imlib
PKGNAMESUFFIX=	-imlib
WITH_IMLIB=	yes
CONFIGURE_ARGS+=	--disable-gdk-pixbuf
.endif

.if exists(${LOCALBASE}/lib/libexif.so.12)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-exit_view.c
.endif

.if exists(${LOCALBASE}/lib/libmng.so.1)
WITH_LIBMNG=	yes
.endif

.if exists(${LOCALBASE}/lib/libwmf.so.2)
WITH_LIBWMF=	yes
.endif

.if exists(${X11BASE}/lib/librsvg.so.1)
WITH_LIBRSVG=	yes
.endif

.if exists(${LOCALBASE}/bin/mplayer)
WITH_MPLAYER=	yes
.endif

.if defined(WITH_LIBMNG)
LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng
PLIST_SUB+=	WITH_LIBMNG=""
.else
PLIST_SUB+=	WITH_LIBMNG="@comment "
.endif

.if defined(WITH_LIBWMF)
LIB_DEPENDS+=	wmf.2:${PORTSDIR}/graphics/libwmf
PLIST_SUB+=	WITH_LIBWMF=""
.else
PLIST_SUB+=	WITH_LIBWMF="@comment "
.endif

.if defined(WITH_LIBRSVG)
LIB_DEPENDS+=	rsvg.1:${PORTSDIR}/graphics/librsvg
PLIST_SUB+=	WITH_LIBRSVG=""
.else
PLIST_SUB+=	WITH_LIBRSVG="@comment "
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
PLIST_SUB+=	WITH_LIBMPLAYER=""
.else
PLIST_SUB+=	WITH_LIBMPLAYER="@comment "
.endif

.if defined(WITH_LIBXINE)
LIB_DEPENDS+=	xine.16:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--with-xine
PLIST_SUB+=	WITH_LIBXINE=""
.else
PLIST_SUB+=	WITH_LIBXINE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/DATADIRNAME=lib/DATADIRNAME=share/g' \
		-e 's|echo aout|echo elf|' \
		${WRKSRC}/configure

post-configure:
.if !defined(WITH_IMLIB)
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} -Ee \
		's/^(GDK_IMLIB_(CFLAGS|LIBS) =).*$$/$${1}/'
.endif

.include <bsd.port.post.mk>
