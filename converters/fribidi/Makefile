PORTNAME=	fribidi
DISTVERSION=	1.0.12
CATEGORIES=	converters
MASTER_SITES=	https://github.com/fribidi/fribidi/releases/download/v${DISTVERSION}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Free Implementation of the Unicode Bidirectional Algorithm

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe meson python:3.6+,test shebangfix tar:xz
CPE_VENDOR=	gnu
SHEBANG_FILES=	test/test-runner.py
USE_LDCONFIG=	yes

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
