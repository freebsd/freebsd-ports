# New ports collection makefile for:   gtkdps
# Version required:    0.2.11
# Date created:        21 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.3 1998/08/05 09:31:09 asami Exp $
#

DISTNAME=	gtkDPS-0.2.11
PKGNAME=	gtkdps-0.2.11
CATEGORIES=	graphics
MASTER_SITES= 	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gyve/fullkit/gyve-0.1.2.4/

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS=	gtk\\.1:${PORTSDIR}/x11-toolkits/gtk
BUILD_DEPENDS=	pswrap:${PORTSDIR}/x11/dgs

CONFIGURE_ARGS=	--with-dps-includes=${X11BASE}/include \
		--with-dps-libraries=${X11BASE}/lib
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
