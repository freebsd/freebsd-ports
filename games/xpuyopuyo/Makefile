# New ports collection makefile for:	xpuyopuyo
# Version required:	0.2.3
# Date created:		19 Sep 1999
# Whom:			Yin-Jieh Chen <yinjieh@csie.nctu.edu.tw>
#
# $FreeBSD$
#

DISTNAME=	xpuyopuyo-0.2.3
CATEGORIES=	games
MASTER_SITES=	http://chaos2.org/xpuyopuyo/

MAINTAINER=	yinjieh@csie.nctu.edu.tw

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gnomeui.2:${PORTSDIR}/x11/gnomelibs

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
CONFIGURE_ARG=	--with-gnome
USE_GMAKE=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/xpuyopuyo
.for i in AUTHORS COPYING ChangeLog INSTALL NEWS README TESTED TODO
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/xpuyopuyo
.endfor
	@${MKDIR} ${PREFIX}/share/xpuyopuyo/img
	@${INSTALL_DATA} ${WRKSRC}/img/*.xpm ${PREFIX}/share/xpuyopuyo/img

.include <bsd.port.mk>
