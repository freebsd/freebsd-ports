# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.3.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.schleef.org/swfdec/download/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		oil-0.2.0:${PORTSDIR}/devel/liboil

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_SDL=	sdl
USE_GNOME=	gnomehack gtk20 libartlgpl2
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e "s,int16_t,__int16_t," ${WRKSRC}/libswfdec/swfdec_shape.c

.include <bsd.port.mk>
