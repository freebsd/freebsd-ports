# New ports collection makefile for:	lzma
# Date created:		25 Apr 2005
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	4.32
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sevenzip
DISTNAME=	lzma${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line lzma archiver

USE_BZIP2=	yes
NO_WRKSUBDIR=	yes
USE_DOS2UNIX=	yes
BUILD_WRKSRC=	${WRKSRC}/C/7zip/Compress/LZMA_Alone
MAKEFILE=	makefile.gcc
PLIST_FILES=	bin/lzma

PORTDOCS=	7zC.txt 7zFormat.txt Methods.txt history.txt lzma.txt

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXX.*||; \
		 s|CXX_C|CC|; \
		 s|^CFLAGS =|CFLAGS +=|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/lzma ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
