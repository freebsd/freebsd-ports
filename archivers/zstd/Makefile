# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zstd
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Zstandard - Fast real-time compression algorithm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ALL_TARGET=	default
MAKE_ARGS=	INCLUDEDIR="${PREFIX}/include" LIBDIR="${PREFIX}/lib" MANDIR="${PREFIX}/man/man1"
USES=		gmake

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	facebook
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|INSTALL_|BSD_&|' ${WRKSRC}/lib/Makefile ${WRKSRC}/programs/Makefile

.include <bsd.port.mk>
