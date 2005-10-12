# New ports collection makefile for:	guichan
# Date created:				2005-10-03
# Whom:					Tobias Gion <freebsd@gionet.de>
#
# $FreeBSD$
#

PORTNAME=	guichan
PORTVERSION=	0.4.0
CATEGORIES=	devel games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	freebsd@gionet.de
COMMENT=	A small, efficient C++ GUI library designed for games

LIB_DEPENDS=	SDL-1.1.7:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes
USE_GCC=	3.2+
USE_LIBTOOL_VER=15
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-allegro
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%LOCALBASE%%/lib

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/SDL11 \
		-I${X11BASE}/include" LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib \
		${PTHREAD_LIBS}"

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

.include <bsd.port.mk>
