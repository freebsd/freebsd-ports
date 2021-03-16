# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	freeimage
PORTVERSION=	3.18.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Source%20Distribution/${PORTVERSION}
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple C/C++ bitmap graphics library

LICENSE=		FIPL GPLv2 GPLv3
LICENSE_COMB=		multi
LICENSE_NAME_FIPL=	FreeImage Public License
LICENSE_FILE_FIPL=	${WRKSRC}/license-fi.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/license-gplv2.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/license-gplv3.txt
LICENSE_PERMS_FIPL=	dist-mirror pkg-mirror auto-accept

BROKEN_mips=		fails to compile: section referenced in discarded section
BROKEN_mips64=		fails to compile: opcode not supported on this processor: mips3 (mips3) 'madd $4,$5'

USES=		dos2unix gmake zip
USE_LDCONFIG=	yes
DOS2UNIX_FILES=	Source/LibOpenJPEG/opj_malloc.h \
		Source/LibRawLite/dcraw/dcraw.c \
		Source/LibRawLite/internal/dcraw_common.cpp \
		Source/FreeImage/PluginBMP.cpp \
		Source/FreeImage/PluginDDS.cpp \
		Source/LibPNG/pngpriv.h

WRKSRC=		${WRKDIR}/FreeImage
MAKE_ARGS=	CC="${CC}" CPP="${CPP}" CXX="${CXX}"
CFLAGS+=	-DPNG_ARM_NEON_OPT=0 -fexceptions -fvisibility=hidden -fPIC
CXXFLAGS+=	-DPNG_ARM_NEON_OPT=0 -fexceptions -fvisibility=hidden -fPIC

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
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}| ; s|-o root -g root || ; \
		/^-fPIC/d' ${WRKSRC}/Makefile.gnu ${WRKSRC}/Makefile.fip

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
