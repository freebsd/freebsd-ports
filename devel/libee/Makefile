# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	libee
PORTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://www.libee.org/files/download/

MAINTAINER=	brd@FreeBSD.org
COMMENT=	An event expression library inspired by CEE

LIB_DEPENDS=	estr:${PORTSDIR}/devel/libestr

MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBESTR_CFLAGS="-I${LOCALBASE}/include" LIBESTR_LIBS="-L${LOCALBASE}/lib -lestr"
CONFIGURE_ARGS+=	--prefix="${PREFIX}" --disable-testbench

NO_STAGE=	yes
.include <bsd.port.mk>
