# New ports collection makefile for: axyftp
# Date created: 		22 October 1998
# Whom: 			Antti Kaipila <anttik@iki.fi>
#
# $FreeBSD$
#

PORTNAME=	axyftp
PORTVERSION=	0.5.1
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.wxftp.seul.org/pub/wxftp/${PORTVERSION}/ \
		ftp://ftp.sunsite.auc.dk/disk2/linuxberg.com/files/x11/network/ \
		ftp://ftp.bitcon.no/.10/linux/linuxberg/files/x11/network/

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=  GTK_CONFIG=${X11BASE}/bin/gtk12-config
USE_X_PREFIX=   yes

MAN1=		axyftp.1

.include <bsd.port.mk>
