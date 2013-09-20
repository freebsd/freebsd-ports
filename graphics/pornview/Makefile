# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pornview
PORTVERSION=	0.2.0.p.1
PORTREVISION=	28
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p./pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PornView is an image viewer/manager

LIB_DEPENDS=	exif:${PORTSDIR}/graphics/libexif \
		png15:${PORTSDIR}/graphics/png \
		xcb-render-util:${PORTSDIR}/x11/xcb-util-renderutil

USE_XORG=	x11 xi xext xinerama
USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	LIBXINE MPLAYER NLS
OPTIONS_DEFAULT=	LIBXINE

NO_STAGE=	yes
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MLIBXINE}
LIB_DEPENDS+=	xine.2:${PORTSDIR}/multimedia/libxine
CONFIGURE_ARGS+=	--enable-xine
.elif ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
CONFIGURE_ARGS+=	--enable-mplayer
.endif
.if ! ${PORT_OPTIONS:MNLS}
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
