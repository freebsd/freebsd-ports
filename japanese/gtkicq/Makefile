# New ports collection makefile for: ja-gtkicq
# Version required: 0.60
# Date created: 8 MAY 1999
# Whom: Shuichi Tanaka
#
# $FreeBSD$
#

DISTNAME=	gtkicq-0.60
PKGNAME=	ja-gtkicq-0.60
CATEGORIES=	japanese net
MASTER_SITES=	ftp://gtkicq.pn.org/pub/gtkicq/

PATCH_SITES=	http://keemun.soraneko.com/gtkicq/archives/
PATCHFILES=	gtkicq-0.60-ja.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	stanaka@bb.mbn.or.jp

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
BUILD_DEPENDS=	${LOCALBASE}/lib/libjcode.a:${PORTSDIR}/japanese/libjcode \
		${LOCALBASE}/include/jlib.h:${PORTSDIR}/japanese/libjcode

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=       yes
USE_GMAKE=      yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--without-gnome
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
