# New ports collection makefile for:	geda
# Version required:		19990124
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	gEDA-19990327
PKGNAME=	geda-19990327
CATEGORIES=	cad
MASTER_SITES=	http://www.geda.seul.org/dist/  \
		ftp://ftp.geda.seul.org/pub/geda/dist/ \
		ftp://ftp.infodrom.north.de/pub/unix/gtk-etc/apps/geda/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		guile.4:${PORTSDIR}/lang/guile

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-gtk-config=${GTK_CONFIG}

.include <bsd.port.mk>
