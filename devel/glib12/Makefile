# New ports collection makefile for:   glib12
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glib
PORTVERSION=	1.2.10
PORTREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/glib/1.2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (previous stable version)

USE_GNOME=	pkgconfig
USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-suffix
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib12
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		glib-config.1
INFO=		glib

post-patch:
	@${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|-lc_r|${PTHREAD_LIBS}|g'

post-install:
	${LN} -sf ${PREFIX}/bin/glib-config ${PREFIX}/bin/glib12-config

.include <bsd.port.mk>
