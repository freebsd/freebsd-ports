# New ports collection makefile for:	gimageview
# Date Created:				5 Feb 2002
# Whom:		TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	gimageview
PORTVERSION=	0.2.25
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmmviewer

MAINTAINER=	katsu@iec.hiroshima-u.ac.jp
COMMENT=	Yet another GTK+ based image viewer

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf
USE_GETTEXT=	yes
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mimlib}!=""
USE_GNOME+=	imlib
PKGNAMESUFFIX=	-imlib
WITH_IMLIB=	yes
.endif

.if exists(${LOCALBASE}/lib/libexif.so.10)
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
LIB_DEPENDS+=	xine.12:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--with-xine
PLIST_SUB+=	WITH_LIBXINE=""
.else
PLIST_SUB+=	WITH_LIBXINE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/DATADIRNAME=lib/DATADIRNAME=share/g' \
		${WRKSRC}/configure

post-configure:
.if !defined(WITH_IMLIB)
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} -Ee \
		's/^(GDK_IMLIB_(CFLAGS|LIBS) =).*$$/$${1}/'
.endif

.include <bsd.port.post.mk>
