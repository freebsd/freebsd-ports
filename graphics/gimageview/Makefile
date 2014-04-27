# Created by: TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
# $FreeBSD$

PORTNAME=	gimageview
PORTVERSION=	0.2.27
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF/gtkmmviewer/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another GTK+ based image viewer

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_XORG=	xinerama ice
CONFIGURE_ARGS=	--with-gtk2
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CFLAGS+=	-DUSE_GTK2
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include"
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	SPLASH NLS LIBMNG LIBWMF LIBRSVG2 LIBEXIF MPLAYER LIBXINE IMLIB
OPTIONS_DEFAULT=SPLASH NLS LIBMNG LIBWMF LIBRSVG2 LIBEXIF MPLAYER
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes

SPLASH_DESC=		Show splash screen on startup
SPLASH_CONFIGURE_ENABLE=splash

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

IMLIB_DESC=		imlib, disable gdk-pixbuf
IMLIB_CONFIGURE_ENABLE=	gdk-pixbuf
IMLIB_USE=		GNOME=imlib

LIBMNG_CONFIGURE_WITH=	libmng
LIBMNG_LIB_DEPENDS=	libmng.so:${PORTSDIR}/graphics/libmng

LIBWMF_CONFIGURE_WITH=	libwmf
LIBWMF_LIB_DEPENDS=	libwmf.so:${PORTSDIR}/graphics/libwmf

LIBRSVG2_CONFIGURE_WITH=librsvg
LIBRSVG2_LIB_DEPENDS=	librsvg-2.so:${PORTSDIR}/graphics/librsvg2

LIBEXIF_CONFIGURE_ENABLE=exif
LIBEXIF_LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif
LIBEXIF_EXTRA_PATCHES=	${FILESDIR}/extra-patch-src-exit_view.c

MPLAYER_CONFIGURE_ENABLE=mplayer
MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

LIBXINE_CONFIGURE_WITH=	xine
LIBXINE_LIB_DEPENDS=	xine:${PORTSDIR}/multimedia/libxine

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/DATADIRNAME=lib/DATADIRNAME=share/g' \
		-e 's|echo aout|echo elf|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/gnome/apps/|/apps/|' \
		${WRKSRC}/gimageview.spec \
		${WRKSRC}/etc/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} \
		's|= $$(DESTDIR)|= |' {} \;

post-configure:
.if ${PORT_OPTIONS:MIMLIB}
	@${FIND} ${WRKSRC} -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} -Ee \
		's/^(GDK_IMLIB_(CFLAGS|LIBS) =).*$$/$${1}/'
.endif

.include <bsd.port.mk>
