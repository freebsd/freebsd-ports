# New ports collection makefile for:	libee
# Date created:		2011-06-20
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	libee
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://www.libee.org/files/download/

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	An event expression library inspired by CEE

LIB_DEPENDS=	estr:${PORTSDIR}/devel/libestr

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBESTR_CFLAGS="-I${LOCALBASE}/include" LIBESTR_LIBS="-L${LOCALBASE}/lib -lestr"
CONFIGURE_ARGS+=	--prefix="${PREFIX}" --disable-testbench

.include <bsd.port.mk>
