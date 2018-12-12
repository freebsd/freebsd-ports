# $FreeBSD$

PORTNAME=	ga
DISTVERSIONPREFIX=	v
DISTVERSION=	5.7
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Partitioned Global Address Space (PGAS) library for distributed arrays

LICENSE=	BMIL
LICENSE_NAME=	Battelle Memorial Institute License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libmpich.so:net/mpich

USES=		autoreconf fortran gmake libtool localbase
USE_GITHUB=	yes
GH_ACCOUNT=	GlobalArrays
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-peigs --enable-shared --disable-static --with-blas4
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
