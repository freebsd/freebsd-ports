PORTNAME=	modules
PORTVERSION=	svn20130912
PORTREVISION=	4
CATEGORIES=	devel games
MASTER_SITES=	https://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	bennugd-
DISTNAME=	bennugd-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High level open source game development suite, modules
WWW=		https://www.bennugd.org/

LIB_DEPENDS=	libbgdrtm.so:devel/bennugd-core \
		libpng.so:graphics/png

USES=		dos2unix libtool pkgconfig sdl tar:bzip2 xorg
USE_SDL=	sdl mixer
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--libdir="${PREFIX}/lib/bennugd"
DOS2UNIX_GLOB=	*.c
INSTALL_TARGET=	install-strip
CFLAGS+=	-Wno-incompatible-function-pointer-types -Wno-int-conversion

WRKSRC=		${WRKDIR}/bennugd/${PORTNAME}

post-extract:
	@${CHMOD} a+x ${WRKSRC}/configure ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
