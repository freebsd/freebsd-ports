PORTNAME=	mtbl
PORTVERSION=	1.6.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Immutable sorted string table library
WWW=		https://github.com/farsightsec/mtbl

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libsnappy.so:archivers/snappy \
		libzstd.so:archivers/zstd

USES=		gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
