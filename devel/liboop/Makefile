# ex:ts=8
# New ports collection makefile for:	liboop
# Date created:			Jun 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	liboop
PORTVERSION=	0.9
CATEGORIES=	devel
MASTER_SITES=	http://download.ofb.net/liboop/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	adns.1:${PORTSDIR}/net/adns \
		wwwcore.1:${PORTSDIR}/www/libwww

USE_BZIP2=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		PROG_GLIB_CONFIG="${GLIB_CONFIG}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	`libwww-config --cflags` -I${LOCALBASE}/include 
LDFLAGS=	`libwww-config --libs` -L${LOCALBASE}/lib

.include <bsd.port.mk>
