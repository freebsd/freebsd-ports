# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zstd
PORTVERSION=	1.1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
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

post-build:
	${MAKE_CMD} -C ${WRKSRC}/contrib/pzstd/

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/pzstd/pzstd ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
