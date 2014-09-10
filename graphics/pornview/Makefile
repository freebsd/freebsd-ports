# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pornview
PORTVERSION=	0.2.0.p.1
PORTREVISION=	29
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p./pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer/manager

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libpng15.so:${PORTSDIR}/graphics/png \
		libxcb-render-util.so:${PORTSDIR}/x11/xcb-util-renderutil

USES=		libtool pkgconfig
USE_XORG=	x11 xi xext xinerama
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk2
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lXext -lX11 -lm

OPTIONS_DEFINE=	LIBXINE MPLAYER NLS
OPTIONS_DEFAULT=	LIBXINE
OPTIONS_SUB=	yes

LIBXINE_CONFIGURE_ENABLE=	xine
LIBXINE_LIB_DEPENDS=	libxine.so:${PORTSDIR}/multimedia/libxine

MPLAYER_CONFIGURE_ENABLE=	mplayer
MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		's|INCLUDED_LIBINTL=yes|INCLUDED_LIBINTL=no|g ; \
		 s|\\[$$][{]top_builddir[}]/intl/libintl.a|-lintl|g' \
		 	${WRKSRC}/configure
	@${REINPLACE_CMD} 's|#define GTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/support/widgets/*.c

.include <bsd.port.mk>
