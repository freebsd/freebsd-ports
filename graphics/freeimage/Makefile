# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	freeimage
PORTVERSION=	3.16.0
PORTREVISION=	3
# Version 3.17.0 is available, but does not build on i386 (and probably
# other 32-bit arches) without some not-quite-trivial patching.  If one
# decides to update the port, please make sure 32-bit builds are tested!
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Source%20Distribution/${PORTVERSION}
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple C/C++ bitmap graphics library

USES=		dos2unix gmake zip
DOS2UNIX_FILES=	Source/LibOpenJPEG/opj_malloc.h \
		Source/LibRawLite/dcraw/dcraw.c \
		Source/LibRawLite/internal/dcraw_common.cpp
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/FreeImage
MAKE_ARGS=	CC="${CC}" CPP="${CPP}" CXX="${CXX}"

CFLAGS+=	-fexceptions -fvisibility=hidden
CFLAGS_aarch64=	-fPIC
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

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == powerpc
USES+=		compiler:c++0x
.endif

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
