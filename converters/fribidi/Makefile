PORTNAME=	fribidi
DISTVERSION=	1.0.16
CATEGORIES=	converters
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Free Implementation of the Unicode Bidirectional Algorithm
WWW=		https://fribidi.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe meson python:test shebangfix tar:xz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

SHEBANG_FILES=	test/test-runner.py

TEST_TARGET=	test

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS TEST
OPTIONS_DEFAULT=OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=	-O3

TEST_MESON_TRUE=tests

post-patch:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' < \
		${FILESDIR}/fribidi-config > ${WRKDIR}/fribidi-config

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/fribidi-config ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
