# New ports collection makefile for:	lzma
# Date created:		25 Apr 2005
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	4.17
CATEGORIES=	archivers
MASTER_SITES=	http://www.7-zip.org/dl/
DISTNAME=	lzma${PORTVERSION:S/.//g}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Command line lzma archiver

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

BUILD_WRKSRC=	${WRKSRC}/SRC/7zip/Compress/LZMA_Alone
MAKEFILE=	makefile
MAKE_ENV=	CC="${CC}" CXX="${CXX}"
PLIST_FILES=	bin/lzma

.if !defined(NOPORTDOCS)
PORTDOCS=	*.txt
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' -exec ${REINPLACE_CMD} -e \
		"s|`${ECHO_CMD} -e '\r'`$$||" {} \;
	@${REINPLACE_CMD} -e \
		's|^CXX.*||; \
		 s|$$(CXX_C)|$$(CC)|; \
		 s|^CFLAGS =|CFLAGS +=|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/lzma ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${RM} -f ${WRKSRC}/LGPL.txt
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
