# New ports collection makefile for:	loserjabber
# Date created:				21 October 2000
# Whom:					ryan
#
# $FreeBSD$
#

PORTNAME=	loserjabber
PORTVERSION=	2.0.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	loserjabber

MAINTAINER=	ryan@manunkind.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

MAN1=		loserjabber.1
MANCOMPRESSED= no

GNU_CONFIGURE= yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

CONFIGURE_ENV= GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
