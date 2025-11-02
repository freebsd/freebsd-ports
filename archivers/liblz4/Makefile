PORTNAME=	lz4
PORTVERSION=	1.10.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/lz4/lz4/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	lib

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	LZ4 compression library, lossless and very fast
WWW=		https://lz4.org/ \
		https://github.com/lz4/lz4

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/lib/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/programs/COPYING

# Note this port is in the dependency chain of lang/python314
# via archivers/zstd and cannot use meson or python to build
USES=		cpe gmake pkgconfig
CPE_VENDOR=	lz4_project
USE_LDCONFIG=	yes

MAKE_ARGS=	PREFIX="${PREFIX}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		MANDIR="${PREFIX}/share/man"
MAKE_ENV+=	TARGET_ARCH=

TEST_TARGET=	check

PORTSCOUT=	limit:^[0-9]*\.

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	TEST
TEST_DESC=	Run complete tests

TEST_TEST_TARGET=test

.include <bsd.port.mk>
