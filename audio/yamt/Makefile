# New ports collection makefile for:	yamt
# Date created:			9 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	yamt
PORTVERSION=	0.5
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dima@Chg.RU

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gnome=${X11BASE}
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
