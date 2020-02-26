# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zstd
PORTVERSION=	1.4.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Zstandard - Fast real-time compression algorithm

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	LZ4
OPTIONS_DEFAULT=LZ4

USES=		gmake

ALL_TARGET=	default
TEST_TARGET=	test
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

GH_ACCOUNT=	facebook
USE_GITHUB=	yes

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_USES=		localbase:ldflags

post-patch:
	@${REINPLACE_CMD} -e 's|INSTALL_|BSD_&|' ${WRKSRC}/lib/Makefile ${WRKSRC}/programs/Makefile

.include <bsd.port.mk>
