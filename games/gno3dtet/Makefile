# New ports collection makefile for:	gno3dtet
# Version required:	0.3.2
# Date created:		21 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	gno3dtet-0.3.2
CATEGORIES=	games
MASTER_SITES=	ftp://webdat.com/pub/seb/gno3dtet/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	gnomeui.3:${PORTSDIR}/x11/gnomelibs

GNOME_CONFIG?=	${X11BASE}/bin/gnome-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GNOME_CONFIG=${GNOME_CONFIG} GTK_CONFIG=${GTK_CONFIG}
CONFIGURE_ARGS+=--prefix=${PREFIX}
USE_X_PREFIX=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/gno3dtet

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
