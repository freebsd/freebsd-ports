# New ports collection makefile for:   glib12
# Date Created:			28 July 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glib
PORTVERSION=	1.2.10
PORTREVISION=	8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/glib/1.2

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

MAINTAINER=	gnome@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-suffix
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib12
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

MAN1=		glib-config.1

post-install:
	${LN} -sf ${PREFIX}/bin/glib-config ${PREFIX}/bin/glib12-config

.include <bsd.port.mk>
