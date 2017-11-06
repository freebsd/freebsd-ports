# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	libee
PORTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.libee.org/files/download/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Event expression library inspired by CEE

LICENSE=	GPLv2

LIB_DEPENDS=	libestr.so:devel/libestr

MAKE_JOBS_UNSAFE=	yes

USES=		libtool pathfix

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBESTR_CFLAGS="-I${LOCALBASE}/include" LIBESTR_LIBS="-L${LOCALBASE}/lib -lestr"
CONFIGURE_ARGS+=	--prefix="${PREFIX}" --disable-testbench

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
