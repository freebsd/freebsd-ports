# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	modules
PORTVERSION=	svn20130912
CATEGORIES=	devel games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
PKGNAMEPREFIX=	bennugd-
DISTNAME=	bennugd-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	High level open source game development suite, modules

LIB_DEPENDS=	libbgdrtm.so:${PORTSDIR}/devel/bennugd-core \
		libpng.so:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SDL=	sdl mixer
GNU_CONFIGURE=	yes
USES=		pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--libdir="${PREFIX}/lib/bennugd"
CONFIGURE_ENV=	ZLIB_CFLAGS=" " ZLIB_LIBS="-lz"

USE_DOS2UNIX=	*.c

WRKSRC=		${WRKDIR}/bennugd/${PORTNAME}

post-extract:
	@${CHMOD} a+x ${WRKSRC}/configure ${WRKSRC}/install-sh

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
