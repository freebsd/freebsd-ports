# New ports collection makefile for:	guichan
# Date created:				2005-10-03
# Whom:					Tobias Gion <freebsd@gionet.de>
#
# $FreeBSD$
#

PORTNAME=	guichan
PORTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	devel games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	freebsd@gionet.de
COMMENT=	A small, efficient C++ GUI library designed for games

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
USE_SDL=	sdl image
USE_GMAKE=	yes
USE_GCC=	3.2+
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--disable-allegro
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%LOCALBASE%%/lib

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/SDL11 \
		-I${X11BASE}/include" LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib \
		${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e "s|%%SDL_CONFIG_ONLY%%|${SDL_CONFIG:S/${PREFIX}\/bin\///}|g" \
		-e "s|%%SDL_CONFIG%%|${SDL_CONFIG}|g" ${WRKSRC}/configure

.include <bsd.port.mk>
