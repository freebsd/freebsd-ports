# New ports collection makefile for:	xmms
# Version required:		0.9.5.1
# Date created:			3 July 1999
# Whom:				Espen Skoglund <esk@ira.uka.de>
#
# $FreeBSD$
#

DISTNAME=	xmms-0.9.5.1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.xmms.org/xmms/0.9/

MAINTAINER=	esk@ira.uka.de

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.3:${PORTSDIR}/devel/glib12 \
		mikmod.2:${PORTSDIR}/audio/libmikmod \
		esd.2:${PORTSDIR}/audio/esound

USE_LIBTOOL=	yes
CONFIGURE_ARGS= --without-gnome

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
 		GLIB_CONFIG="${GLIB_CONFIG}"

.include <bsd.port.mk>
