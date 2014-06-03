# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	libconcord
PORTVERSION=	1.1
CATEGORIES=	comms
MASTER_SITES=	SF/concordance/concordance/${PORTVERSION}
DISTNAME=	concordance-${PORTVERSION}

MAINTAINER=	shurd@sasktel.net
COMMENT=	Logitech Harmony configuration library

LICENSE=	GPLv2

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconf
LIB_DEPENDS=	libhidapi.so:${PORTSDIR}/comms/hidapi \
		libzip.so:${PORTSDIR}/archivers/libzip

USE_LDCONFIG=	yes
USES=		tar:bzip2 libtool shared-mime-info
WRKSRC_SUBDIR=	libconcord
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
