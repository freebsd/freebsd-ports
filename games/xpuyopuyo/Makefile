# New ports collection makefile for:	xpuyopuyo
# Version required:	0.2.7
# Date created:		19 Sep 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	xpuyopuyo-0.3.3
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xpuyopuyo/ \
		http://lenin.dabney.caltech.edu/~justins/xpuyopuyo/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
CONFIGURE_ARGS=	--enable-rotate-fixed --without-gnome

MAN6=		xpuyopuyo.6

.include <bsd.port.mk>
