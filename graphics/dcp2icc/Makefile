# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dcp2icc
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	graphics converters
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Version%20${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	DCP to ICC camera profile converter

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		liblcms.so:graphics/lcms

USES=		localbase:ldflags scons tar:bzip2
USE_GCC=	any	# segfaults on exit when built with Clang

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${UNZIP_NATIVE_CMD} -qo ${WRKSRC}/XMP-Toolkit-SDK-4.4.2.zip \
		-d ${WRKSRC}
	@${UNZIP_NATIVE_CMD} -qo ${WRKSRC}/dng_sdk_1_2.zip -d ${WRKSRC}

post-patch:
	@${MV} -f ${WRKSRC}/fixes/XMP-Toolkit/XMPFiles.hpp \
		${WRKSRC}/XMP-Toolkit-SDK-4.4.2/source/XMPFiles
	@${MV} -f ${WRKSRC}/fixes/XMP-Toolkit/LargeFileAccess.hpp \
		${WRKSRC}/XMP-Toolkit-SDK-4.4.2/source/common
	@${MV} -f ${WRKSRC}/fixes/dng_sdk/dng_hue_sat_map.h \
		${WRKSRC}/dng_sdk_1_2/dng_sdk/source
	@${REINPLACE_CMD} -e '/mimetype/s,delete,&[],' \
		${WRKSRC}/XMP-Toolkit-SDK-4.4.2/source/XMPFiles/FileHandlers/UCF_Handler.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
