# New ports collection makefile for:	DirectFB
# Date created:				19 October 2002
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	directfb
PORTVERSION=	0.9.16
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.directfb.org/download/DirectFB/
DISTNAME=	DirectFB-${PORTVERSION}

MAINTAINER=	fab@gcu.info
COMMENT=	Graphic development lightweight API

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		png.5:${PORTSDIR}/graphics/png

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
	    	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
PLIST_SUB+=	DIRECTFB_VERSION=${PORTVERSION}

.if exists(${LOCALBASE}/lib/libfreetype.so.9)
WITH_FREETYPE2=	yes
.endif

.if defined(WITH_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
CONFIGURE_ARGS+=	--enable-freetype
PLIST_SUB+=	WITH_FREETYPE2=""
.else
CONFIGURE_ARGS+=	--disable-freetype
PLIST_SUB+=	WITH_FREETYPE2="@comment "
.endif

MAN1=		directfb-csource.1 dfbg.1
MAN5=		directfbrc.5

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

.include <bsd.port.mk>
