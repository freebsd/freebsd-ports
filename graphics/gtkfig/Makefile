# New ports collection makefile for:	gtkfig
# Date created:		Tue Nov 17 13:51:11 CET 1998
# Whom:			Dirk Froemberg <ibex@physik.TU-Berlin.DE>
#
# $FreeBSD$
#

PORTNAME=	gtkfig
PORTVERSION=	0.6.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://k332.feld.cvut.cz/pub/local/lemming/gtkfig/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	dirk@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
