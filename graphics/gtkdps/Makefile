# New ports collection makefile for:   gtkdps
# Version required:    0.3.1
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	gtkDPS-0.3.1
PKGNAME=	gtkdps-0.3.1
CATEGORIES=	graphics
MASTER_SITES= 	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gtkDPS/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

BUILD_DEPENDS=	pswrap:${PORTSDIR}/x11/dgs

CONFIGURE_ARGS=	--with-dps-includes=${X11BASE}/include \
		--with-dps-libraries=${X11BASE}/lib
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
USE_LIBTOOL=	yes

.include <bsd.port.mk>
