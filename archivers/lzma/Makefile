PORTNAME=	lzma
PORTVERSION=	26.00
CATEGORIES=	archivers
MASTER_SITES=	SF/sevenzip/LZMA%20SDK/
DISTNAME=	lzma${PORTVERSION:S/.//g}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	High-ratio LZMA compressor
WWW=		https://www.7-zip.org/sdk.html

LICENSE=	PD
LICENSE_TEXT_PD=	LZMA SDK is written and placed in the public \
		domain by Igor Pavlov Anyone. Anyone is free to copy, modify, \
		publish, use, compile, sell, or distribute the original LZMA \
		SDK code, either in source code form or as a compiled binary, \
		for any purpose, commercial or non-commercial, and by any means.

BUILD_DEPENDS_amd64=	jwasm:devel/jwasm
BUILD_DEPENDS_i386=	jwasm:devel/jwasm
BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
USES=		7z dos2unix gmake

CPE_VENDOR=	7-zip
MAKEFILE=	makefile.gcc
CONFLICTS=	lzmautils xz

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Bundles/LzmaCon

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt lzma-history.txt lzma-specification.txt lzma.txt
MAKE_ARGS+=	${MAKE_ARGS_${ARCH}} \
		LOCAL_FLAGS="${CFLAGS}" \
		CFLAGS_WARN_WALL="-Wall -Wextra"
MAKE_ARGS_aarch64=	USE_ASM=1 IS_ARM64=1
MAKE_ARGS_amd64=	USE_ASM=1 IS_X64=1 USE_JWASM=1
MAKE_ARGS_i386=		USE_ASM=1 IS_X86=1 USE_JWASM=1

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/_o/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/DOC/&&${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-test:
	${BUILD_WRKSRC}/_o/${PORTNAME} b

.include <bsd.port.mk>
