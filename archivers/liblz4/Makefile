PORTNAME=	lz4
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.3
PORTEPOCH=	1
CATEGORIES=	archivers
PKGNAMEPREFIX=	lib

MAINTAINER=	martin@waschbuesch.de
COMMENT=	LZ4 compression library, lossless and very fast

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USES=		cpe meson pkgconfig python:3.5+,build shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes
CPE_VENDOR=	lz4_project

SHEBANG_FILES=	meson/*.py \
		${WRKDIR}/${PORTNAME}-${DISTVERSION}/tests/*.py

MESON_ARGS=	-Ddefault_library=both -Dbin_programs=true

WRKSRC_SUBDIR=	contrib/meson

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	TEST

TEST_MESON_TRUE=	bin_tests

.include <bsd.port.mk>
