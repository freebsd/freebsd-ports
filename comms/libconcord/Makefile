# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libconcord
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	SF/concordance/concordance/${PORTVERSION}
DISTNAME=	concordance-${PORTVERSION}

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	Logitech Harmony configuration library

LICENSE=	GPLv2

LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libzip.so:archivers/libzip

USE_LDCONFIG=	yes
USES=		tar:bzip2 libtool pkgconfig shared-mime-info
WRKSRC_SUBDIR=	libconcord
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
