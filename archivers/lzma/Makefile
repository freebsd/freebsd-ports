# New ports collection makefile for:	lzma
# Date created:		25 Apr 2005
# Whom:			Radim Kolar <hsn@netmag.cz>
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	9.07
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SF/sevenzip/7-Zip/${PORTVERSION}%20beta/
DISTNAME=	lzma${PORTVERSION:S/.//g}

MAINTAINER=	bf1783@gmail.com
COMMENT=	High-ratio LZMA compressor

CONFLICTS=	lzmautils-[0-9]* xz-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Compress/LZMA_Alone
MAKEFILE=	makefile.gcc
PLIST_FILES=	bin/${PORTNAME}
CFLAGS+=	-D_LZMA_SYSTEM_SIZE_T
.ifdef(WITH_LZMA_PROB32)
#increase the speed of decoding on some 32-bit CPUs, at the expense of doubled
#memory usage for CLzmaDec::probs
CFLAGS+=	-D_LZMA_PROB32
.endif
.ifdef(WITH_LZMA_SIZE_OPT)
#enable some optimizations in LZMA Decoder to get smaller executable code
CFLAGS+=	-D_LZMA_SIZE_OPT
.endif
PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt history.txt lzma.txt

post-patch:
	@${REINPLACE_CMD} -e '/bool Open(LPCTSTR fileName, DWORD creationDisposition)/,/}/d'\
		${WRKSRC}/CPP/7zip/Common/FileStreams.h
	@${REINPLACE_CMD} -e \
		'/^CXX/d;s|CXX_C|CC|;s|^CFLAGS =|CFLAGS +=|;s|-o|${CFLAGS} -o|'\
			${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

regression-test: build
	${BUILD_WRKSRC}/${PORTNAME} b

.include <bsd.port.mk>
