PORTNAME=	flac
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/flac/ \
		https://ftp.osuosl.org/pub/xiph/releases/flac/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec
WWW=		https://www.xiph.org/flac/

LICENSE=	BSD3CLAUSE GFDL GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/COPYING.Xiph
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.FDL

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		compiler:c11 cpe iconv libtool pathfix pkgconfig tar:xz

CPE_VENDOR=	flac_project

# Preserve UTF-8 filenames in test/flac-to-flac-metadata-test-files/.
# They are referenced by the test suite.
EXTRACT_CMD=	${SETENV} LC_ALL=C.UTF-8 ${TAR}

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static \
		--disable-sse \
		--with-ogg="${LOCALBASE}" \
		--disable-doxygen-docs \
		--disable-thorough-tests \
		--disable-xmms-plugin
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

.if ${ARCH} != powerpc64le
CONFIGURE_ARGS+=--disable-vsx
.endif

.include <bsd.port.mk>
