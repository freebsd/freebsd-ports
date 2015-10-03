# $FreeBSD$

PORTNAME=	waifu2x-converter-cpp
DISTVERSION=	1.0.0-237
DISTVERSIONSUFFIX=	-gca65c93
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	https://aur.archlinux.org/cgit/aur.git/plain/:manpage
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME:C/-.*//}.1.gz?h=${PORTNAME:C/-.*//}-git\&id=5c150a5:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Scale and denoise images using convolutional neural networks

LICENSE=	BSD2CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/CL/opencl.h:${PORTSDIR}/devel/opencl
LIB_DEPENDS=	libopencv_highgui.so:${PORTSDIR}/graphics/opencv \
		libopencv_imgproc.so:${PORTSDIR}/graphics/opencv-core

USE_GITHUB=	yes
GH_ACCOUNT=	tanakamura

USES=		cmake compiler:c++11-lib dos2unix
DOS2UNIX_GLOB=	*.cpp *.hpp
CMAKE_ARGS=	-DOPENCV_PREFIX="${LOCALBASE}" \
		-DOpenCL_LIBRARY="${LOCALBASE}/lib/libOpenCL.so" \
		-DCMAKE_SKIP_RPATH=on # XXX use cmake install() instead
CFLAGS+=	-D_GLIBCXX_USE_C99 -D_GLIBCXX_USE_C99_MATH_TR1 \
		-D_DECLARE_C99_LDBL_MATH # XXX ports/193528
LDFLAGS+=	-Wl,--as-needed # avoid overlinking (opencv deps)
USE_LDCONFIG=	yes
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		include/w2xconv.h \
		lib/libw2xc.so
PORTDATA=	models_rgb
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS SIMD
OPTIONS_DEFAULT=SIMD

SIMD_CMAKE_OFF=	-DX86OPT=off

post-extract:
	@${GZCAT} ${_DISTDIR}/${DISTFILES:M*\:manpage:C/:.*//} \
		>${WRKDIR}/${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,,; /SYMBOL/s,-s,,' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/"models/s,","${DATADIR}/,' \
		-e '/CmdLine/s,[^"]*"),${DISTVERSIONFULL}"),' \
		${WRKSRC}/src/main.cpp
# Undo AUR rename and use version from |git describe --tags|
	@${REINPLACE_CMD} -e '/AUTHORS/,$$! { /\.B mai/! \
			s,${PORTNAME:C/-.*//},${PORTNAME},; }' \
		-e '1s,\(version\) [^"]*,\1 ${DISTVERSIONFULL},' \
		${WRKDIR}/${PORTNAME}.1

pre-install:
# XXX Fails on 9.x with error code 10
	-(cd ${WRKSRC} && LD_LIBRARY_PATH=. ./runtest)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_LIB} ${WRKSRC}/libw2xc.so ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} -p ${WRKSRC}/src/w2xconv.h \
		${STAGEDIR}${PREFIX}/include
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDATA}" ${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "appendix" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \
		"internals" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
