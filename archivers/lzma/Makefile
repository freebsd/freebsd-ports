# New ports collection makefile for:	lzma
# Date created:		25 Apr 2005
# Whom:			Radim Kolar <hsn@netmag.cz>
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	4.58
CATEGORIES=	archivers
MASTER_SITES=	SFE/sevenzip
DISTNAME=	lzma${PORTVERSION:S/.//g}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	High-ratio LZMA compressor

CONFLICTS=	lzmautils-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Compress/LZMA_Alone
MAKEFILE=	makefile.gcc
PLIST_FILES=	bin/${PORTNAME}
CFLAGS+=	-D_LZMA_SYSTEM_SIZE_T
PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt history.txt lzma.txt

post-patch:
	@${REINPLACE_CMD} -e 's|4\.56|${DISTVERSION}|' \
		${BUILD_WRKSRC}/LzmaAlone.cpp
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

.include <bsd.port.mk>
