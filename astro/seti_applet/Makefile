# New ports collection makefile for:	seti_applet
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seti_applet
PORTVERSION=	0.3.0
CATEGORIES=	astro gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	th@cis.ibaraki.ac.jp

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore \
		gnome.4:${PORTSDIR}/x11/gnomelibs \
		gtop.1:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	setiathome:${PORTSDIR}/astro/setiathome \
		gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

USE_X_PREFIX=	yes

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_LIBTOOL=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
	${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g" ${PKGMESSAGE}

.include <bsd.port.mk>
