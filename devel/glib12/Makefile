# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glib
PORTVERSION=	1.2.10
PORTREVISION=	14
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

INFO=		glib

post-install:
	${LN} -sf ${PREFIX}/bin/glib-config ${STAGEDIR}${PREFIX}/bin/glib12-config
.for lib in glib gmodule gthread
	@${RM} ${STAGEDIR}${PREFIX}/lib/lib${lib}.la ${STAGEDIR}${PREFIX}/lib/lib${lib}.so
	@${MV} ${STAGEDIR}${PREFIX}/lib/lib${lib}.a ${STAGEDIR}${PREFIX}/lib/lib${lib}-12.a
.endfor

.include <bsd.port.mk>
