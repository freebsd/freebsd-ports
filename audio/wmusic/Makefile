# New ports collection makefile for:	wmusic
# Date created:				16 September 2000
# Whom:					Eric Melville <eric@osd.bsdi.com>
#
# $FreeBSD$
#

PORTNAME=	wmusic
PORTVERSION=	1.2.6
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://hadess.net/files/

MAINTAINER=	eric@osd.bsdi.com

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp
BUILD_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE} \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"

USE_GLIB=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
