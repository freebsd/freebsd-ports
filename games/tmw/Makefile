# New ports collection makefile for:	tmw
# Date created:				12 Oktober 2005
# Whom:					Tobias Gion
#
# $FreeBSD$
#

PORTNAME=	tmw
PORTVERSION=	0.0.17
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	themanaworld

MAINTAINER=	freebsd@gionet.de
COMMENT=	A free open source 2D MMORPG in development

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		png.5:${PORTSDIR}/graphics/png \
		curl.3:${PORTSDIR}/ftp/curl \
		physfs-1.0.1:${PORTSDIR}/devel/physfs \
		guichan.0:${PORTSDIR}/devel/guichan

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_SDL=	sdl image mixer net

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CXXFLAGS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
