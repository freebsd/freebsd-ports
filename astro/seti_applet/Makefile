# New ports collection makefile for:	seti_applet
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seti_applet
PORTVERSION=	0.2.2
CATEGORIES=	astro gnome
MASTER_SITES=	http://download.sourceforge.net/seti-applet/

MAINTAINER=	th@cis.ibaraki.ac.jp

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore \
		gnome.4:${PORTSDIR}/x11/gnomelibs
RUN_DEPENDS=	setiathome:${PORTSDIR}/astro/setiathome

USE_X_PREFIX=	yes
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes

CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}"

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
