# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad

USE_X_PREFIX=	yes
USE_SDL=	yes
USE_GNOME=	gnomehack gtk20 libartlgpl2
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG:T}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|malloc\.h|stdlib.h|g" ${WRKSRC}/libswfdec/jpeg/sl_types.h

.include <bsd.port.mk>
