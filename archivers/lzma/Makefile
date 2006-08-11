# New ports collection makefile for:	lzma
# Date created:		25 Apr 2005
# Whom:			Radim Kolar <hsn@netmag.cz>
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	4.43
CATEGORIES=	archivers
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	sevenzip
DISTNAME=	lzma${PORTVERSION:S/.//g}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	High-ratio LZMA compressor

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes
BUILD_WRKSRC=	${WRKSRC}/C/7zip/Compress/LZMA_Alone
MAKEFILE=	makefile.gcc
PLIST_FILES=	bin/lzma
CFLAGS+=	-D_LZMA_SYSTEM_SIZE_T

PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt history.txt lzma.txt

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXX.*||; \
		 s|CXX_C|CC|; \
		 s|^CFLAGS =|CFLAGS +=|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/lzma ${TARGETDIR}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
