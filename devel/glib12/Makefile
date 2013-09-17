# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glib
PORTVERSION=	1.2.10
PORTREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	12

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Some useful routines of C programming (previous stable version)

USE_CSTD=	gnu89
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/glib12

MAN1=		glib-config.1
INFO=		glib

post-install:
	${LN} -sf ${PREFIX}/bin/glib-config ${PREFIX}/bin/glib12-config
.for lib in glib gmodule gthread
	@${RM} ${PREFIX}/lib/lib${lib}.la ${PREFIX}/lib/lib${lib}.so
	@${MV} ${PREFIX}/lib/lib${lib}.a ${PREFIX}/lib/lib${lib}-12.a
.endfor

.include <bsd.port.mk>
