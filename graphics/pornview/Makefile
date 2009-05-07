# New ports collection Makefile for: pornview
# Date created:		24 Nov 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pornview
PORTVERSION=	0.2.0.p.1
PORTREVISION=	20
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p./pre/}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PornView is an image viewer/manager

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif
LIB_DEPENDS+=	xcb-render-util:${PORTSDIR}/x11/xcb-util

USE_XORG=	x11 xi xext xinerama
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_LIBXINE)
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--enable-xine
.elif defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	WITH_NLS="@comment "
.else
PLIST_SUB+=	WITH_NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g ; \
		 s|\\[$$][{]top_builddir[}]/intl/libintl.a|-lintl|g' \
		 	${WRKSRC}/configure
	@${REINPLACE_CMD} 's|#define GTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/support/widgets/*.c

.include <bsd.port.mk>
