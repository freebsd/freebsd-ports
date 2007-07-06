# New ports collection makefile for:	CImg
# Date created:         11 September 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	cimg
PORTVERSION=	1.2.2
PORTEPOCH=	1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	CImg-${DISTVERSION}
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The C++ Template Image Processing Library

USE_ZIP=	yes
BUILD_WRKSRC=	${WRKSRC}/examples
MAKE_ENV=	CPPFLAGS="${CFLAGS} ${LAPACK_DEF} ${PTHREAD_CFLAGS}"	\
		LDFLAGS="${LDFLAGS} ${LAPACK_LIB} ${PTHREAD_LIBS}"	\
		X11PATH=${X11BASE}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
USE_GCC=	3.4+
REINPLACE_ARGS=	-i ""
. if !defined(WITHOUT_LAPACK)
LIB_DEPENDS+=	atlas.2:${PORTSDIR}/math/atlas
LAPACK_LIB=	-L${LOCALBASE}/lib -lalapack -lcblas -lf77blas -L`${CAT} ${WRKSRC}/LIBDIR`/../../.. -lgfortran -latlas
LAPACK_DEF=	-Dcimg_lapack
. endif

WANT_FORTRAN=	yes #dummy but future use
BUILD_DEPENDS+=	gfortran42:${PORTSDIR}/lang/gcc42
FC=		gfortran42
F77=		gfortran42

. if !defined(WITHOUT_OPTIMIZATIONS)
USE_XLIB=	yes
LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png		\
		jpeg:${PORTSDIR}/graphics/jpeg		\
		tiff:${PORTSDIR}/graphics/tiff		\
		Magick:${PORTSDIR}/graphics/ImageMagick	\
		fftw3:${PORTSDIR}/math/fftw3
ALL_TARGET=	oFreeBSD
.else
ALL_TARGET=	dFreeBSD
. endif

DOCBASE=	CHANGES.txt README.txt
DOCREFS=	download.shtml favicon.ico favicon.png foot_reference.html	\
		head.html head_reference.html img index.shtml links.shtml	\
		news.shtml reference screenshots.shtml
.else
NOBUILD=	yes
.endif

.if !defined(WITHOUT_IM)
RUN_DEPENDS+=	${LOCALBASE}/lib/libMagick.so.10:${PORTSDIR}/graphics/ImageMagick
.endif

pre-configure:
	${DIRNAME} `${LOCALBASE}/bin/${F77} -print-libgcc-file-name` > ${WRKSRC}/LIBDIR
.if !defined(NOPORTDOCS)
	${GREP} -lR 'img/' ${BUILD_WRKSRC} |	\
		${XARGS} ${REINPLACE_CMD} -e 's|img/|${EXAMPLESDIR}/img/|g'
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
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCBASE:S|^|${WRKSRC}/|} ${DOCSDIR}
. for doc in ${DOCREFS}
	${CP} -R ${WRKSRC}/documentation/${doc} ${DOCSDIR}
. endfor
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@(cd ${EXAMPLESDIR} && ${MAKE} clean)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} ${EXAMPLESDIR}
	${FIND} ${DOCSDIR} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.endif

.include <bsd.port.mk>
