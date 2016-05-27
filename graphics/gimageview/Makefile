# Created by: TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
# $FreeBSD$

PORTNAME=	gimageview
PORTVERSION=	0.2.27
PORTREVISION=	21
CATEGORIES=	graphics
MASTER_SITES=	SF/gtkmmviewer/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Yet another GTK+ based image viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake jpeg libtool localbase pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_XORG=	ice xinerama
CONFIGURE_ARGS=	--with-gtk2
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	SPLASH NLS LIBMNG LIBWMF LIBRSVG2 LIBEXIF MPLAYER LIBXINE DOCS
OPTIONS_DEFAULT=SPLASH LIBMNG LIBWMF LIBRSVG2 LIBEXIF MPLAYER
OPTIONS_SUB=	yes

SPLASH_DESC=		Show splash screen on startup
SPLASH_CONFIGURE_ENABLE=splash

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

LIBMNG_CONFIGURE_WITH=	libmng
LIBMNG_LIB_DEPENDS=	libmng.so:graphics/libmng

LIBWMF_CONFIGURE_WITH=	libwmf
LIBWMF_LIB_DEPENDS=	libwmf.so:graphics/libwmf

LIBRSVG2_CONFIGURE_WITH=librsvg
LIBRSVG2_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2

LIBEXIF_CONFIGURE_ENABLE=exif # bundled exif is used
LIBEXIF_BROKEN_OFF=	does not build without libexif support

MPLAYER_CONFIGURE_ENABLE=mplayer
MPLAYER_RUN_DEPENDS=	mplayer:multimedia/mplayer

LIBXINE_CONFIGURE_WITH=	xine
LIBXINE_LIB_DEPENDS=	libxine.so:multimedia/libxine

post-patch:
	@${REINPLACE_CMD} '/^desktopdir =/s|=.*|= ${DESKTOPDIR}|' \
		${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} '/^gimv_LDADD =/s/=/= -lm/' ${WRKSRC}/src/Makefile.in
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} \
		-e 's|= $$(DESTDIR)|= |' -e '/^CPPFLAGS =/s/\\/@CPPFLAGS@ \\/'

.include <bsd.port.mk>
