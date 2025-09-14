PORTNAME=	jpeg-turbo
DISTVERSION=	3.1.2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/lib${PORTNAME}/lib${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	lib${PORTNAME}-${DISTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT?=	SIMD-accelerated JPEG codec which replaces libjpeg
WWW?=		https://libjpeg-turbo.org/

LICENSE=		BSD3CLAUSE IJG ZLIB
LICENSE_COMB=		multi
LICENSE_GROUPS_IJG=	FSF GPL
LICENSE_NAME_IJG=	Independent JPEG Group License
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.md
LICENSE_FILE_IJG=	${WRKSRC}/README.ijg
LICENSE_FILE_ZLIB=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_IJG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		cmake cpe pathfix
CPE_PRODUCT=	libjpeg-turbo
USE_LDCONFIG=	yes

TEST_TARGET=	test

PORTDOCS=	*
DOCSDIR=	${PREFIX}/share/doc/libjpeg-turbo

CMAKE_ON=	WITH_JPEG8
# See https://github.com/libjpeg-turbo/libjpeg-turbo/issues/705
CMAKE_ARGS=	-DCMAKE_CTEST_ARGUMENTS="-E;'djpeg12-shared-3x2-float-prog-cmp|djpeg12-static-3x2-float-prog-cmp'"

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == armv6
CMAKE_OFF=	WITH_SIMD
.endif

.if ${SLAVE_PORT} == yes
PLIST_SUB+=	JPEG="@comment " LIBTURBOJPEG=""
.else
CMAKE_OFF+=	WITH_TURBOJPEG
CONFLICTS_INSTALL=	mozjpeg
PLIST_SUB+=	JPEG="" LIBTURBOJPEG="@comment "
.endif

.include <bsd.port.mk>
