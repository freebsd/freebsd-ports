# New ports collection makefile for:	gtkcomm
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	gtkcomm
PORTVERSION=	0.5.9
CATEGORIES=	korean comms
MASTER_SITES=	http://kldp.org/~namsh/tools/gtkcomm/

MAINTAINER=	cjh@kr.freebsd.org

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		Imlib.5:${PORTSDIR}/graphics/imlib

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	GLIB_CONFIG=${LOCALBASE}/bin/glib12-config \
		GTK_CONFIG=${X11BASE}/bin/gtk12-config

.include <bsd.port.mk>
