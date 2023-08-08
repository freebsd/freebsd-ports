PORTNAME=	lz4
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.4
PORTEPOCH=	1
CATEGORIES=	archivers
PKGNAMEPREFIX=	lib

MAINTAINER=	martin@waschbuesch.de
COMMENT=	LZ4 compression library, lossless and very fast
WWW=		https://lz4.github.io/lz4/

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		cpe meson pkgconfig python:build shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
CPE_VENDOR=	lz4_project

SHEBANG_FILES=	meson/*.py \
		${WRKDIR}/${PORTNAME}-${DISTVERSION}/tests/*.py

MESON_ARGS=	-Ddefault_library=both -Dprograms=true

WRKSRC_SUBDIR=	contrib/meson

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	TEST

TEST_MESON_TRUE=	tests

.include <bsd.port.mk>
