# New ports collection makefile for:	gdesklets
# Date created:				11 August 2003
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gdesklets
PORTVERSION=	0.34.2
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.pycage.de/download/${PORTNAME}/
DISTNAME=	gDesklets-${PORTVERSION}

MAINTAINER=	klammer@webonaut.com
COMMENT=	A framework for Gnome 2.x for desktop applets

LIB_DEPENDS=	gtop-2.0.2:${PORTSDIR}/devel/libgtop2

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack librsvg2 pygnomeextras

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"

GCONF_SCHEMAS=	gdesklets-display-thumbnail.schemas
MAN1=		gdesklets.1

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Displays
	@${MKDIR} ${PREFIX}/share/gnome/gdesklets/Sensors
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/lib/gdesklets
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
