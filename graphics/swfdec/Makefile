# ex:ts=8
# Ports collection makefile for:	swfdec
# Date created:			Apr 5, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	swfdec
PORTVERSION=	0.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash Rendering Library

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		mad.1:${PORTSDIR}/audio/mad

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk20 libartlgpl2
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|malloc\.h|stdlib.h|" ${WRKSRC}/libswfdec/jpeg/sl_types.h

.include <bsd.port.mk>
