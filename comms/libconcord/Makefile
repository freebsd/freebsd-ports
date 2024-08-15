PORTNAME=	libconcord
PORTVERSION=	1.5
CATEGORIES=	comms
MASTER_SITES=	SF/concordance/concordance/${PORTVERSION}
DISTNAME=	concordance-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logitech Harmony configuration library

LICENSE=	GPLv2
DEPRECATED=     Logitech Harmony were officially discontinued in 2021, last major product in 2019.
EXPIRATION_DATE=2024-12-31

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhidapi.so:comms/hidapi \
		libzip.so:archivers/libzip

USE_LDCONFIG=	yes
USES=		tar:bzip2 libtool pkgconfig shared-mime-info
WRKSRC_SUBDIR=	libconcord
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
