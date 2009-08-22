# New ports collection makefile for:	ppmd-7z
# Date created:		1 September 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ppmd
PORTVERSION=	4.65
CATEGORIES=	archivers
MASTER_SITES=	SF/p7zip/p7zip/${PORTVERSION}
PKGNAMESUFFIX=	-7z
DISTNAME=	p7zip_${DISTVERSION}_src_all

MAINTAINER=	bf1783@gmail.com
COMMENT=	High-ratio PPMD compressor

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/p7zip_${DISTVERSION}
BUILD_WRKSRC=	${WRKSRC}/CPP/7zip/Compress/PPMD_Alone
MAKEFILE=	makefile
PLIST_FILES=	bin/${PKGBASE}
MAKE_ARGS=	PROG=${PORTNAME} CXX="${CXX}" LIB="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e '/bool Open(LPCTSTR fileName, DWORD creationDisposition)/,/}/d'\
		${WRKSRC}/CPP/7zip/Common/FileStreams.h
	@${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS +=|;s|-o |${CFLAGS} -o |'\
			${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PKGBASE}

regression-test: build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

.include <bsd.port.mk>
