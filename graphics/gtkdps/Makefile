# New ports collection makefile for:   gtkdps
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gtkdps
PORTVERSION=	0.3.2
CATEGORIES=	graphics
MASTER_SITES= 	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gtkDPS/
DISTNAME=	gtkDPS-${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
BUILD_DEPENDS=	pswrap:${PORTSDIR}/x11/dgs

CONFIGURE_ARGS=	--with-dps-includes=${X11BASE}/include \
		--with-dps-libraries=${X11BASE}/lib
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
USE_LIBTOOL=	yes

.include <bsd.port.mk>
