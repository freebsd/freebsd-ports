# New ports collection makefile for:	extace
# Date created:				8 April 2000
# Whom:					Maxim Sobolev
#
# $FreeBSD$
#

PORTNAME=		extace
PORTVERSION=		1.2.23
CATEGORIES=		audio
MASTER_SITES=		http://download.sourceforge.net/eXtace/

MAINTAINER=		sobomax@FreeBSD.org

LIB_DEPENDS=		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
			gdk_imlib.5:${PORTSDIR}/graphics/imlib \
			esd.2:${PORTSDIR}/audio/esound \
			fftw.2:${PORTSDIR}/math/fftw

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes

GTK_CONFIG?=		${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=		${LOCALBASE}/bin/glib12-config
ESD_CONFIG?=		${LOCALBASE}/bin/esd-config

CONFIGURE_ENV=		GTK_CONFIG="${GTK_CONFIG}" \
			GLIB_CONFIG="${GLIB_CONFIG}" \
			ESD_CONFIG="${ESD_CONFIG}" \
			LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
