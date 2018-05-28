# $FreeBSD$

PORTNAME=	mtbl
PORTVERSION=	1.2.1
CATEGORIES=	devel
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Immutable sorted string table library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd

GNU_CONFIGURE=	yes
USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
