# $FreeBSD$

PORTNAME=	mtbl
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Immutable sorted string table library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libsnappy.so:${PORTSDIR}/archivers/snappy

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix pkgconfig
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>

# The version of binutils in base does not understand the crc32
# instructions used in this code on amd64.  Use gcc from ports
# to get a more capable version of binutils.
.if (${OPSYS} == FreeBSD && ${OSVERSION} < 900000 && ${ARCH} == amd64)
USE_GCC=	yes
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.post.mk>
