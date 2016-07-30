# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zstd
PORTVERSION=	0.7.4
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Zstandard - Fast real-time compression algorithm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/lib/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Cyan4973

ALL_TARGET=	default
MAKE_ARGS=	MANDIR="${PREFIX}/man/man1" \
		LIBDIR="${PREFIX}/lib" \
		INCLUDEDIR="${PREFIX}/include"

.include <bsd.port.mk>
