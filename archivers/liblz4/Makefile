PORTNAME=	lz4
PORTVERSION=	1.10.0
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
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/../../lib/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/../../programs/COPYING

USES=		cpe meson pkgconfig python:build

MESON_ARGS=	--default-library=both \
		-Dalign-test=true \
		-Dcontrib=false \
		-Ddebug-level=1 \
		-Ddistance-max=65535 \
		-Denable_multithread=true \
		-Dexamples=false \
		-Dfast-dec-loop='auto' \
		-Dforce-sw-bitcount=false \
		-Dfreestanding=false \
		-Dmemory-usage=0 \
		-Dossfuzz=true \
		-Dprograms=true \
		-Dunstable=false \
		-Duser-memory-functions=false
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	build/meson

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	lz4_project

PORTSCOUT=	limit:^[0-9]*\.

OPTIONS_DEFINE=	TEST

TEST_MESON_TRUE=	tests

.include <bsd.port.mk>
