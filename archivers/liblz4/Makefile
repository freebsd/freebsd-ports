PORTNAME=	lz4
PORTVERSION=	1.9.4
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
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/../../lib/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/../../programs/COPYING

USES=		cpe meson pkgconfig python:build shebangfix

MESON_ARGS=	--default-library=both \
		-Dcontrib=false \
		-Dexamples=false \
		-Dmemory-usage=0 \
		-Dprograms=true \
		-Dunstable=false
USE_LDCONFIG=	yes
WRKSRC_SUBDIR=	contrib/meson

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	lz4_project

PORTSCOUT=	limit:^[0-9]*\.

SHEBANG_FILES=	../../tests/*.py meson/*.py

OPTIONS_DEFINE=	TEST

TEST_MESON_TRUE=	tests

.include <bsd.port.mk>
