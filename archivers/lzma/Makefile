# Created by: Radim Kolar <hsn@netmag.cz>
# $FreeBSD$

PORTNAME=	lzma
PORTVERSION=	19.00
CATEGORIES=	archivers
MASTER_SITES=	SF/sevenzip/LZMA%20SDK/
DISTNAME=	lzma${PORTVERSION:S/.//g}

MAINTAINER=	ndowens@yahoo.com
COMMENT=	High-ratio LZMA compressor

CONFLICTS=	lzmautils-[0-9]* xz-[0-9]*

USES=		7z gmake dos2unix
NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Bundles/LzmaCon
MAKEFILE=	makefile.gcc
PLIST_FILES=	bin/${PORTNAME}
.ifdef(WITH_LZMA_PROB32)
#increase the speed of decoding on some 32-bit CPUs, at the expense of doubled
#memory usage for CLzmaDec::probs
CFLAGS+=	-D_LZMA_PROB32
.endif
.ifdef(WITH_LZMA_SIZE_OPT)
#enable some optimizations in LZMA Decoder to get smaller executable code
CFLAGS+=	-D_LZMA_SIZE_OPT
.endif
PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt lzma-history.txt lzma.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/bool Open(LPCTSTR fileName, DWORD creationDisposition)/,/}/d'\
		${WRKSRC}/CPP/7zip/Common/FileStreams.h
	@${REINPLACE_CMD} -e 's|malloc\.h|stdlib.h|g' \
		${WRKSRC}/CPP/7zip/UI/Common/Bench.cpp \
		${WRKSRC}/CPP/Common/MyWindows.cpp
	@${REINPLACE_CMD} -e \
		'/^CXX/d;s|CXX_C|CC|;s|^CFLAGS =|CFLAGS +=|;s|-o|${CFLAGS} -o|'\
			${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/DOC/&&${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-test:
	${BUILD_WRKSRC}/${PORTNAME} b

.include <bsd.port.mk>
