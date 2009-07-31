# New ports collection makefile for:	akamaru
# Date created:		2006 10 10
# Whom:			Phillip Neumann <pneumann@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	akamaru
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://people.freedesktop.org/~krh/
DISTNAME=	${PORTNAME}

MAINTAINER=	pneumann@gmail.com
COMMENT=	Simple, but fun, physics engine prototype

BUILD_DEPENDS=	gtk-demo:${PORTSDIR}/x11-toolkits/gtk20
RUN_DEPENDS=	gtk-demo:${PORTSDIR}/x11-toolkits/gtk20 \
		xcompmgr:${PORTSDIR}/x11-wm/xcompmgr

USE_GMAKE=	yes
USE_GNOME=	gconf2 gnomehier
GCONF_SCHEMAS=	kiba.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
	    	${WRKSRC}/populate-dock.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/dock ${PREFIX}/bin/kiba-dock
	@${INSTALL_PROGRAM} ${WRKSRC}/akamaru ${PREFIX}/bin/akamaru
	@${INSTALL_DATA} ${WRKSRC}/kiba.schemas ${LOCALBASE}/etc/gconf/schemas
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/populate-dock.sh ${PREFIX}/share/${PORTNAME}
	@${SETENV} GCONF_CONFIG_SOURCE=${GCONF_CONFIG_SOURCE} gconftool-2 --makefile-install-rule ${PREFIX}/etc/gconf/schemas/kiba.schemas

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} "*** By default kiba-dock is empty."
	@${ECHO_MSG} "*** To add launchers, look and run the script ${PREFIX}/share/${PORTNAME}/populate-dock.sh"
	@${ECHO_MSG}

.include <bsd.port.mk>
