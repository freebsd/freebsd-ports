PORTNAME=	lz4
PORTVERSION=	1.11.1
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

USES=		cpe gmake pkgconfig

CFLAGS+=	-DLZ4IO_MULTITHREAD -pthread
LDFLAGS+=	-pthread
MAKE_ARGS=	PREFIX="${PREFIX}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV=	TARGET_ARCH=
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

BINARY_ALIAS=	make=${GMAKE}

CPE_VENDOR=	lz4_project

PORTSCOUT=	limit:^[0-9]*\.

OPTIONS_DEFINE=	TEST
TEST_DESC=	Run extensive tests

TEST_TEST_TARGET=	test
TEST_TEST_TARGET_OFF=	check
TEST_USES=	python:-3.13,test

.include <bsd.port.mk>
