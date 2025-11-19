PORTNAME=	efivar
PORTVERSION=	39
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Tools and libraries to work with EFI variables
WWW=		https://github.com/rhboot/efivar

LICENSE=	LGPL21

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	specification only supports little-endian processors
BROKEN_FreeBSD_13=	requires at least FreeBSD 14

BUILD_DEPENDS=	gsed:textproc/gsed
LIB_DEPENDS=	libpopt.so:devel/popt

USES=		gmake pkgconfig python

USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rhboot
USE_LDCONFIG=	yes
BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

MAKE_ARGS+=	CC="${CC}" LIBDIR="${PREFIX}/lib" \
		LDFLAGS="-Wl,-rpath,${PREFIX}/lib"

.include <bsd.port.mk>
