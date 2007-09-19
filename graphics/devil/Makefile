# New ports collection makefile for:   devil
# Date created:        8 August 2004
# Whom:                Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	devil
PORTVERSION=	1.6.7
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openil
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A full featured cross-platform image library

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		mng.1:${PORTSDIR}/graphics/libmng \
		lcms.1:${PORTSDIR}/graphics/lcms

USE_AUTOTOOLS=	libtool:15
USE_GL=		yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-allegro
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

OPTIONS=	SDL "Enable SDL support" off

.include <bsd.port.pre.mk>

.if defined(WITH_SDL)
USE_SDL=	yes
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

post-patch:
	${FIND} ${WRKSRC} \( -name '*.c' -o -name '*.cpp' -o -name '*.h' \) -print0 |\
		${XARGS} -0 ${REINPLACE_CMD} 's|ILvoid|void|g'

.include <bsd.port.post.mk>
