# New ports collection makefile for:    netpanzer
# Date created:				29 May 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	netpanzer-data
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/netpanzer/

MAINTAINER=	mad@madpilot.net
COMMENT=	Data files for the netpanzer game

LIB_DEPENDS=	physfs-1.0.1:${PORTSDIR}/devel/physfs
BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libphysfs=${LOCALBASE}
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_SDL=	sdl net mixer image
USE_GNOME=	libxml2
USE_GCC=	3.4

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} jam)

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} jam ${INSTALL_TARGET})

.include <bsd.port.mk>
