# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	1999.05.16
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cc.gatech.edu/ac121/linux/X11/gtkbuffet/apps/geda/ \
		ftp://ftp.geda.seul.org/pub/geda/dist/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtk-etc/apps/geda/
DISTNAME=	gEDA-19990516

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		guile.6:${PORTSDIR}/lang/guile

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-gtk-config=${GTK_CONFIG}

MAN1=		gschem.1 gnetlist.1

.include <bsd.port.mk>
