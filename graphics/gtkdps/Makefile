# New ports collection makefile for:   gtkdps
# Version required:    0.2.16
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.8 1999/01/12 16:50:44 vanilla Exp $
#

DISTNAME=	gtkDPS-0.2.16
PKGNAME=	gtkdps-0.2.16
CATEGORIES=	graphics
MASTER_SITES= 	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gyve/fullkit/gyve-0.2.1/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gtk10.1:${PORTSDIR}/x11-toolkits/gtk10
BUILD_DEPENDS=	pswrap:${PORTSDIR}/x11/dgs

CONFIGURE_ARGS=	--with-dps-includes=${X11BASE}/include \
		--with-dps-libraries=${X11BASE}/lib
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk10-config"
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
