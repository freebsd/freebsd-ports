# New ports collection makefile for:	xmms-tfmx
# Date created:			21 May 2000
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmms-tfmx
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/

MAINTAINER=	anders@fix.no

LIB_DEPENDS=	xmms.1:${PORTSDIR}/audio/xmms

USE_LIBTOOL=	yes
USE_GMAKE=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
