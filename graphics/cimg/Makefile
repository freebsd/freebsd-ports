# New ports collection makefile for:	CImg
# Date created:         11 September 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	cimg
PORTVERSION=	1.2.8
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics devel
MASTER_SITES=	SF
DISTNAME=	CImg-${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION},${PORTEPOCH}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The C++ Template Image Processing Library

USE_ZIP=	yes
BUILD_WRKSRC=	${WRKSRC}/examples
MAKE_ENV=	CPPFLAGS="${CFLAGS} ${LAPACK_DEF} ${PTHREAD_CFLAGS}"	\
		LDFLAGS="${LDFLAGS} ${LAPACK_LIB} ${PTHREAD_LIBS}"	\
		X11PATH=${LOCALBASE}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
USE_GMAKE=	yes
REINPLACE_ARGS=	-i ""
LIB_DEPENDS+=	board.0:${PORTSDIR}/graphics/libboard
. if !defined(WITHOUT_LAPACK)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas -lf77blas -L`${CAT} ${WRKSRC}/LIBDIR`/../../.. -lgfortran -latlas
LAPACK_DEF=	-Dcimg_lapack
. endif

USE_FORTRAN=	yes

. if !defined(WITHOUT_OPTIMIZATIONS)
LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png		\
		jpeg:${PORTSDIR}/graphics/jpeg		\
		tiff:${PORTSDIR}/graphics/tiff		\
		Magick:${PORTSDIR}/graphics/ImageMagick	\
		fftw3:${PORTSDIR}/math/fftw3
ALL_TARGET=	oFreeBSD
. else
ALL_TARGET=	dFreeBSD
. endif

. if !defined(WITHOUT_GM)
RUN_DEPENDS+=	gm:${PORTSDIR}/graphics/GraphicsMagick
. endif
. if !defined(WITHOUT_MEDCON)
RUN_DEPENDS+=	medcon:${PORTSDIR}/graphics/xmedcon
. endif
. if !defined(WITHOUT_FFMPEG)
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
. endif

DOCBASE=	CHANGES.txt README.txt
DOCREFS=	CImg.doxygen CImg_documentation.h CImg_reference.pdf chat.shtml	\
		download.shtml favicon.ico favicon.png footer.html header.html	\
		header_reference.html img index.shtml links.shtml news.shtml	\
		reference screenshots.shtml
.else
NO_BUILD=	yes
.endif

pre-configure:
.if !defined(NOPORTDOCS)
	${DIRNAME} `${LOCALBASE}/bin/${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
	${GREP} -lR 'img/' ${BUILD_WRKSRC} |	\
		${XARGS} ${REINPLACE_CMD} -e 's|"img/|"${EXAMPLESDIR}/img/|g'
	${REINPLACE_CMD} -e 's|make|${GMAKE}|' ${BUILD_WRKSRC}/Makefile
.else
	${REINPLACE_CMD} -e 's|^OPTFLAGS|#OPTFLAGS|' ${BUILD_WRKSRC}/Makefile
.endif

.if !defined(NOPORTDOCS)
post-build:
	cd ${WRKSRC}/documentation && doxygen CImg.doxygen
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/CImg.h ${PREFIX}/include
.if !defined(NOPORTDOCS)
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/CImg_demo ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOCBASE:S|^|${WRKSRC}/|} ${DOCSDIR}
. for doc in ${DOCREFS}
	${CP} -R ${WRKSRC}/documentation/${doc} ${DOCSDIR}
. endfor
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@(cd ${EXAMPLESDIR} && ${GMAKE} clean)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	${FIND} ${DOCSDIR} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.endif

.include <bsd.port.mk>
