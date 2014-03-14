# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	freeimage
PORTVERSION=	3.15.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Source%20Distribution/${PORTVERSION}
DISTNAME=	FreeImage${PORTVERSION:S/.//g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Simple C/C++ bitmap graphics library

USES=		gmake dos2unix zip
DOS2UNIX_FILES=	Source/LibOpenJPEG/opj_malloc.h
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/FreeImage
MAKE_ARGS=	CC=${CC} CPP=${CPP} CXX=${CXX}

CFLAGS+=	-fexceptions -fvisibility=hidden

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}| ; s|-o root -g root ||' \
		${WRKSRC}/Makefile.gnu ${WRKSRC}/Makefile.fip

post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile.fip ${_MAKE_JOBS} ${MAKE_ARGS}

post-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} -f Makefile.fip ${MAKE_ARGS} ${INSTALL_TARGET}
	${LN} -s libfreeimageplus.so.3 ${STAGEDIR}${PREFIX}/lib/libfreeimageplus.so
	${LN} -s libfreeimageplus-${PORTVERSION}.so ${STAGEDIR}${PREFIX}/lib/libfreeimageplus.so.3

.include <bsd.port.post.mk>
