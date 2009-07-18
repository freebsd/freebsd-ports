# New ports collection makefile for:	DirectFB
# Date created:				19 October 2002
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	directfb
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/downloads/Core/ \
		http://www.directfb.org/downloads/Old/
DISTNAME=	DirectFB-${PORTVERSION}

MAINTAINER=	anatoly.borodin@gmail.com
COMMENT=	Graphic development lightweight API

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
USE_AUTOTOOLS=	libtool:15
USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes
USE_PERL5=	yes
PLIST_SUB+=	DIRECTFB_VERSION=${PORTVERSION} DIRECTFB_VER=1.1-0

.if exists(${LOCALBASE}/lib/libfreetype.so.9)
WITH_FREETYPE2=	yes
.endif

.if defined(WITH_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--enable-freetype
PLIST_SUB+=	FREETYPE2=""
.else
CONFIGURE_ARGS+=	--disable-freetype
PLIST_SUB+=	FREETYPE2="@comment "
.endif

.if defined(WITH_X11)
USE_XORG+=	x11 xproto
CONFIGURE_ARGS+=	--enable-x11
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=	--disable-x11
PLIST_SUB+=	X11="@comment "
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
CONFIGURE_ARGS+=	--enable-sdl
PLIST_SUB+=	SDL="" GFXDRIVERS=""
.else
CONFIGURE_ARGS+=	--disable-sdl
PLIST_SUB+=	SDL="@comment " GFXDRIVERS="@comment "

.endif

.if defined(WITH_SDL) || defined(WITH_X11)
PLIST_SUB+=	INPUTDRIVERS=""
.else
PLIST_SUB+=	INPUTDRIVERS="@comment "
.endif

MAN1=		directfb-csource.1 dfbg.1
MAN5=		directfbrc.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		Does not compile on alpha
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-lc_r/${PTHREAD_LIBS}/g ; \
		s/-lpthread/${PTHREAD_LIBS}/g ; s|%%LTMAIN%%|${LTMAIN}|g' \
			${WRKSRC}/configure

.include <bsd.port.post.mk>
