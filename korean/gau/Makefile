# New ports collection makefile for:    gau
# Version required:     0.3.1
# Date created:         23 Jul 1998
# Whom:                 CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	gau-0.4.1
PKGNAME=	ko-gau-0.4.1
CATEGORIES=	korean comms
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/gau/

PATCH_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/
PATCHFILES=	gau-0.4.1.patch gau-0.4.1-rc.patch gau-0.4.1-grim_show.patch \
		gau-0.4.1-script.patch gau-0.4.1-warning.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cjh@kr.freebsd.org

LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		${X11BASE}/lib/X11/fonts/local/gulim12.pcf.gz:${PORTSDIR}/korean/baekmukfonts-bdf

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  GLIB_CONFIG=${LOCALBASE}/bin/glib12-config \
		GTK_CONFIG=${X11BASE}/bin/gtk12-config

.include <bsd.port.mk>
