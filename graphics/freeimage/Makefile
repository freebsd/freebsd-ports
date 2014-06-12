# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	freeimage
PORTVERSION=	3.16.0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Source%20Distribution/${PORTVERSION}
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple C/C++ bitmap graphics library

USES=		dos2unix gmake zip
DOS2UNIX_FILES=	Source/LibOpenJPEG/opj_malloc.h
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/FreeImage
MAKE_ARGS=	CC="${CC}" CPP="${CPP}" CXX="${CXX}"

CFLAGS+=	-fexceptions -fvisibility=hidden
CFLAGS_amd64=	-fPIC

PLIST_FILES=	include/FreeImage.h \
		include/FreeImagePlus.h \
		lib/libfreeimage.a \
		lib/libfreeimage-${PORTVERSION}.so \
		lib/libfreeimage.so.3 \
		lib/libfreeimage.so \
		lib/libfreeimageplus.a \
		lib/libfreeimageplus-${PORTVERSION}.so \
		lib/libfreeimageplus.so.3 \
		lib/libfreeimageplus.so

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}| ; s|-o root -g root ||' \
		${WRKSRC}/Makefile.gnu ${WRKSRC}/Makefile.fip

post-build:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f Makefile.fip ${_MAKE_JOBS} \
		${MAKE_ARGS} -C ${BUILD_WRKSRC}

post-install:
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} -f Makefile.fip ${MAKE_ARGS} \
		-C ${INSTALL_WRKSRC} ${INSTALL_TARGET}
	${LN} -sf libfreeimageplus.so.3 \
		${STAGEDIR}${PREFIX}/lib/libfreeimageplus.so
	${LN} -sf libfreeimageplus-${PORTVERSION}.so \
		${STAGEDIR}${PREFIX}/lib/libfreeimageplus.so.3

.include <bsd.port.mk>
