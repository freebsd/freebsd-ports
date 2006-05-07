# New ports collection makefile for:   devil
# Date created:        8 August 2004
# Whom:                Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	devil
PORTVERSION=	1.6.7
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openil
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	andreas@syndrom23.de
COMMENT=	A full featured cross-platform image library

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		mng.1:${PORTSDIR}/graphics/libmng \
		lcms.1:${PORTSDIR}/graphics/lcms

OPTIONS=	SDL "Enable SDL support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SDL)
USE_SDL=	yes
CFLAGS+=	"-I${LOCALBASE}/include/SDL11"
.endif

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib \
		-L${X11BASE}/lib"

.if defined(WITH_SDL)
post-patch:
	@${REINPLACE_CMD} 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/configure
.endif

.include <bsd.port.post.mk>
