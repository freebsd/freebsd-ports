# New ports collection makefile for:	geda
# Version required:		19990327
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	gEDA-19990516
PKGNAME=	geda-19990516
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.cc.gatech.edu/ac121/linux/X11/gtkbuffet/apps/geda/ \
		ftp://ftp.geda.seul.org/pub/geda/dist/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtk-etc/apps/geda/

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		guile.6:${PORTSDIR}/lang/guile

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-gtk-config=${GTK_CONFIG}

.include <bsd.port.mk>
