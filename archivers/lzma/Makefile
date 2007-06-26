# New ports collection makefile for:	lzma
# Date created:		25 Apr 2005
# Whom:			Radim Kolar <hsn@netmag.cz>
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	4.48
CATEGORIES=	archivers
MASTER_SITES=	SFE/sevenzip
DISTNAME=	7z${PORTVERSION:S/.//g}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	High-ratio LZMA compressor

USE_BZIP2=	yes
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Compress/LZMA_Alone
MAKEFILE=	makefile.gcc
PLIST_FILES=	bin/lzma
CFLAGS+=	-D_LZMA_SYSTEM_SIZE_T

PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt history.txt lzma.txt

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXX.*||;s|CXX_C|CC|;s|^CFLAGS =|CFLAGS +=|'\
			${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/lzma ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/DOC/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
