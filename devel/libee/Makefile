# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	libee
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.libee.org/files/download/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Event expression library inspired by CEE

LIB_DEPENDS=	libestr.so:devel/libestr

MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

USES=		libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBESTR_CFLAGS="-I${LOCALBASE}/include" LIBESTR_LIBS="-L${LOCALBASE}/lib -lestr"
CONFIGURE_ARGS+=	--prefix="${PREFIX}" --disable-testbench

.include <bsd.port.mk>
