# New ports collection makefile for:	wmusic
# Date created:				16 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	wmusic
PORTVERSION=	1.4.4
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://hadess.net/files/

MAINTAINER=	eric@FreeBSD.org

BUILD_DEPENDS=	xmms:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}
CONFIGURE_ENV=	PATH_GTKCONFIG=${X11BASE}/bin/gtk12-config

USE_GLIB=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
